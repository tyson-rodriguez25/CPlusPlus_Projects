#include "Database.h"


void database::evaluateDatalog(datalogProgram datalog) {  // Edited
	evaluateSchemes(datalog);
	evaluateFacts(datalog); // Edited

	bool changed = true;
	int passes = 0;
	std::vector<relation*> relationsCheck;
	while (changed) {
		changed = false;
		for (unsigned int i = 0; i < relations.size(); i++)
			relationsCheck.push_back(relations[i]);
		for (int i = 0; i < datalog.getRuleSize(); i++) {
			datalog.getRule(i)->toString(); // Edited
			evaluateRule(datalog.getRule(i)); // Edited
			for (unsigned int j = 0; j < relations.size(); j++) {
				if (relations[j] != relationsCheck[j])
					changed = true;
			}
		}
		passes++;
		relationsCheck.clear();
	}
	cout << "Schemes populated after " << passes << " passes through the Rules." << endl; // Edited
	//cout << datalog.getQuerySize() << endl;
	for (int i = 0; i < datalog.getQuerySize(); i++) {
		
		cout << datalog.getQuery(i)->toString(); // Edited
		cout << evaluateQuery(datalog.getQuery(i)); // Edited
		cout << std::endl;
;
	}

	return;
}

void database::evaluateSchemes(datalogProgram datalog) {
	scheme* newSchemes;
	for (int i = 0; i < datalog.getSchemeSize(); i++) {
		newSchemes = new scheme();
		for (int j = 0; j < datalog.getScheme(i)->getParameterSize(); j++)
			newSchemes->addAttributeName(datalog.getScheme(i)->getParameter(j)->getValue());
		relations.push_back(new relation(datalog.getScheme(i)->getID(), newSchemes, {}));
	}
	return;
}

void database::evaluateFacts(datalogProgram datalog) {
	Tuple* newTuples;
	for (int i = 0; i < datalog.getFactSize(); i++) {
		newTuples = new Tuple();
		for (int j = 0; j < datalog.getFact(i)->getParameterSize(); j++)
			newTuples->addAttribute(datalog.getFact(i)->getParameter(j)->getValue());
		for (int j = 0; j < relations.size(); j++) {
			if (datalog.getFact(i)->getID() == relations[j]->getName())
				relations[j]->addTuple(newTuples);
		}
	}
	return;
}

std::string database::evaluateQuery(predicate* query) {
	int relationNumber;
	relation* temp1;
	relation* temp2;
	std::string soFar = "";

	for (int i = 0; i < relations.size(); i++) {
		if (relations[i]->getName() == query->getID())
			relationNumber = i;
	}
	scheme* newScheme = new scheme();
	newScheme->addAttributeNames(relations[relationNumber]->getScheme()->getAttributeNames());
	std::vector<Tuple*> newList;
	for (int i = 0; i < relations[relationNumber]->getTuplesSize(); i++) {
		Tuple* newTuple = new Tuple();
		newTuple->addAttributes(relations[relationNumber]->getTuple(i)->getAttributes());
		newList.push_back(newTuple);
	}

	temp1 = new relation(relations[relationNumber]->getName(), newScheme, newList);

	for (int i = 0; i < query->getParameterSize(); i++) {
		if (query->getParameter(i)->getType() == "STRING") {
			temp2 = temp1;
			temp1 = temp1->selectByValue(i, query->getParameter(i)->getValue());
			delete temp2;
		}
		else {
			for (int j = i + 1; j < query->getParameterSize(); j++) {
				if (query->getParameter(i)->getValue() == query->getParameter(j)->getValue()) {
					temp2 = temp1;
					temp1 = temp1->selectByComparison(i, j);
					delete temp2;
				}
			}
		}
	}

	if (temp1->getTuplesSize() == 0) {
		delete temp1;
		return "? No";
	}

	std::vector<int> variablesPosition;
	std::vector<std::string> variables;

	for (int i = 0; i < query->getParameterSize(); i++) {
		if (query->getParameter(i)->getType() == "ID" && std::find(variables.begin(), variables.end(), query->getParameter(i)->getValue()) == variables.end()) {
			variablesPosition.push_back(i);
			variables.push_back(query->getParameter(i)->getValue());
		}
	}
	temp2 = temp1;
	temp1 = temp1->project(variablesPosition);
	delete temp2;

	scheme* tempScheme = new scheme();
	tempScheme->addAttributeNames(variables);

	temp2 = temp1;
	temp1 = temp1->rename(tempScheme);
	delete temp2;
	delete tempScheme;

	temp2 = temp1;
	temp1 = temp1->removeDups();
	delete temp2;

	temp1->sortTuples();

	soFar += "? Yes(";
	if (temp1->getTuplesSize() == 0) {
		soFar += "1";
		soFar += ")";
	}
	else {
		soFar += std::to_string(temp1->getTuplesSize());
		soFar += ")\n";
	}

	for (int i = 0; i < temp1->getTuplesSize(); i++) {
		if (i != 0)
			soFar += "\n";
		soFar += "  ";
		for (int j = 0; j < variables.size(); j++) {
			if (j > 0)
				soFar += ", ";

			soFar += variables[j];
			soFar += "=";
			soFar += temp1->getTuple(i)->getAttribute(j);
		}
	}

	delete temp1;
	return soFar;
}

std::string database::evaluateRule(rule* rule) {
	std::vector<relation*> ACRelations;
	scheme* s;
	Tuple* t;
	std::vector<Tuple*> newTuples;

	for (int i = 0; i < rule->getACPredicates().size(); i++) {
		s = new scheme();
		for (int j = 0; j < rule->getACPredicate(i)->getParameterSize(); j++)
			s->addAttributeName(rule->getACPredicate(i)->getParameter(j)->getValue());
		for (int j = 0; j < relations.size(); j++) {
			if (rule->getACPredicate(i)->getID() == relations[j]->getName()) {
				for (int k = 0; k < relations[j]->getTuplesSize(); k++) {
					t = new Tuple();
					t->addAttributes(relations[j]->getTuple(k)->getAttributes());
					newTuples.push_back(t);
				}
			}
		}
		ACRelations.push_back(new relation(rule->getACPredicate(i)->getID(), s, newTuples));
		newTuples.clear();
	}

	relation* temp1 = ACRelations[0];
	relation* temp2;
	if (ACRelations.size() > 1) {
		for (int i = 1; i < ACRelations.size(); i++) {
			temp2 = temp1;
			temp1 = temp1->joinCombine(temp1, ACRelations[i]);
			delete temp2;
		}
	}

	for (int i = 1; i < ACRelations.size(); i++)
		delete ACRelations[i];

	for (int i = 0; i < temp1->getScheme()->getAttributeNames().size(); i++) {
		if (temp1->getScheme()->getAttributeName(i).substr(0, 1) == "'") {
			temp2 = temp1;
			temp1 = temp1->selectByValue(i, temp1->getScheme()->getAttributeName(i));
			delete temp2;
		}
		else {
			for (int j = i + 1; j < temp1->getScheme()->getAttributeNames().size(); j++) {
				if (temp1->getScheme()->getAttributeName(i) == temp1->getScheme()->getAttributeName(j)) {
					temp2 = temp1;
					temp1 = temp1->selectByComparison(i, j);
					delete temp2;
				}
			}
		}
	}
	
	std::vector<int> columns;
	for (int i = 0; i < rule->getBCPredicate()->getParameterSize(); i++) {
		for (int j = 0; j < temp1->getScheme()->getAttributeNames().size(); j++) {
			if (rule->getBCPredicate()->getParameter(i)->getValue() == temp1->getScheme()->getAttributeName(j)) {
				columns.push_back(j);
				break;
			}
		}
	}

	temp2 = temp1;
	temp1 = temp1->project(columns);
	delete temp2;

	int relationsPos = 0;
	for (int i = 0; i < relations.size(); i++) {
		if (rule->getBCPredicate()->getID() == relations[i]->getName())
			relationsPos = i;
	}

	temp2 = temp1;
	temp1 = temp1->rename(relations[relationsPos]->getScheme());
	delete temp2;
	temp1->sortTuples();

	temp2 = temp1;
	temp1 = temp1->unionCombine(relations[relationsPos], temp1);
	delete temp2;

	std::string soFar = "";
	for (int i = relations[relationsPos]->getTuplesSize(); i < temp1->getTuplesSize(); i++) {
		for (int j = 0; j < temp1->getScheme()->getAttributeNames().size(); j++) {
			if (j == 0)
				soFar += "  ";
			else
				soFar += ", ";
			soFar += temp1->getScheme()->getAttributeName(j);
			soFar += "=";
			soFar += temp1->getTuple(i)->getAttribute(j);
		}
		soFar += "\n";
	}

	temp1->sortTuples();

	if (relations[relationsPos]->getTuplesSize() != temp1->getTuplesSize()) {
		temp2 = relations[relationsPos];
		relations[relationsPos] = temp1;
		delete temp2;
	}
	else
		delete temp1;

	return soFar;
}

void database::clear() {
	for (int i = 0; i < relations.size(); i++)
		delete relations[i];
	relations.clear();
	return;
}