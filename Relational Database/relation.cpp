#include "relation.h"

std::string relation::getName() {
	return name;
}

Tuple* relation::getTuple(int position) {
	return Tuples[position];
}

std::vector<Tuple*> relation::getTuples() {
	return Tuples;
}

int relation::getTuplesSize() {
	return Tuples.size();
}

scheme* relation::getScheme() {
	return rScheme;
}

void relation::addTuple(Tuple* newTuple) {
	Tuples.push_back(newTuple);
	return;
}

relation* relation::selectByValue(int position, std::string value) {
	std::vector<Tuple*> selected;
	for (int i = 0; i < Tuples.size(); i++) {
		if (Tuples[i]->getAttribute(position) == value) {
			Tuple* replaceTuple = new Tuple();
			replaceTuple->addAttributes(Tuples[i]->getAttributes());
			selected.push_back(replaceTuple);
		}
	}
	scheme* replaceScheme = new scheme();
	replaceScheme->addAttributeNames(rScheme->getAttributeNames());
	return new relation(name, replaceScheme, selected);
}

relation* relation::selectByComparison(int position1, int position2) {
	std::vector<Tuple*> selected;
	for (int i = 0; i < Tuples.size(); i++) {
		if (Tuples[i]->getAttribute(position1) == Tuples[i]->getAttribute(position2)) {
			Tuple* newTuple = new Tuple();
			newTuple->addAttributes(Tuples[i]->getAttributes());
			selected.push_back(newTuple);
		}
	}
	scheme* replaceScheme = new scheme();
	replaceScheme->addAttributeNames(rScheme->getAttributeNames());
	return new relation(name, replaceScheme, selected);
}

relation* relation::project(std::vector<int> positions) {
	scheme* projectScheme = new scheme();
	std::vector<Tuple*> projectTuples;

	for (int i = 0; i < positions.size(); i++) {
		projectScheme->addAttributeName(rScheme->getAttributeName(positions[i]));

		for (int j = 0; j < Tuples.size(); j++) {
			if (i == 0) {
				Tuple* TupleMaker = new Tuple();
				projectTuples.push_back(TupleMaker);
			}
			projectTuples[j]->addAttribute(Tuples[j]->getAttribute(positions[i]));
		}
	}
	return new relation(name, projectScheme, projectTuples);
}

relation* relation::rename(scheme* replaceScheme) {
	std::vector<Tuple*> newList;
	for (int i = 0; i < Tuples.size(); i++) {
		Tuple* newTuple = new Tuple();
		newTuple->addAttributes(Tuples[i]->getAttributes());
		newList.push_back(newTuple);
	}
	scheme* newScheme = new scheme();
	newScheme->addAttributeNames(replaceScheme->getAttributeNames());
	return new relation(name, newScheme, newList);
}

relation* relation::unionCombine(relation* first, relation* second) {
	bool allMatch = true;
	if (first->getScheme()->getAttributeNames().size() != second->getScheme()->getAttributeNames().size())
		return nullptr;
	for (int i = 0; i < first->getScheme()->getAttributeNames().size(); i++) {
		if (first->getScheme()->getAttributeName(i) != second->getScheme()->getAttributeName(i))
			allMatch = false;
	}
	if (!allMatch)
		return nullptr;

	scheme* s = new scheme();
	s->addAttributeNames(first->getScheme()->getAttributeNames());
	Tuple* t;
	std::vector<Tuple*> newTuples;
	for (int i = 0; i < first->getTuplesSize(); i++) {
		t = new Tuple();
		t->addAttributes(first->getTuple(i)->getAttributes());
		newTuples.push_back(t);
	}

	relation* r = new relation(first->getName(), s, newTuples);
	bool alreadyThere;

	for (int i = 0; i < second->getTuplesSize(); i++) {
		alreadyThere = false;
		for (int j = 0; j < r->getTuplesSize(); j++) {
			if (second->getTuple(i)->getAttributes() == r->getTuple(j)->getAttributes())
				alreadyThere = true;
			if (alreadyThere)
				break;
		}
		if (!alreadyThere) {
			t = new Tuple();
			t->addAttributes(second->getTuple(i)->getAttributes());
			r->addTuple(t);
		}
	}

	return r;
}

relation* relation::joinCombine(relation* first, relation* second) {
	scheme* s = new scheme();
	for (int i = 0; i < first->getScheme()->getAttributeNames().size(); i++)
		s->addAttributeName(first->getScheme()->getAttributeName(i));
	for (int i = 0; i < second->getScheme()->getAttributeNames().size(); i++)
		s->addAttributeName(second->getScheme()->getAttributeName(i));

	std::vector< std::vector<int> > matching;
	for (int i = 0; i < first->getScheme()->getAttributeNames().size(); i++) {
		for (int j = 0; j < second->getScheme()->getAttributeNames().size(); j++) {
			if (first->getScheme()->getAttributeName(i) == second->getScheme()->getAttributeName(j))
				matching.push_back({ i,j });
		}
	}
	std::string newName = first->getName() + "+" + second->getName();
	std::vector<Tuple*> newTuples;
	relation* r = new relation(newName, s, newTuples);

	Tuple* t;
	if (matching.size() == 0) {
		int size = std::min(first->getTuplesSize(), second->getTuplesSize());
		for (int i = 0; i < size; i++) {
			t = new Tuple();
			for (int j = 0; j < first->getScheme()->getAttributeNames().size(); j++)
				t->addAttribute(first->getTuple(i)->getAttribute(j));
			for (int j = 0; j < second->getScheme()->getAttributeNames().size(); j++)
				t->addAttribute(second->getTuple(i)->getAttribute(j));
			r->addTuple(t);
		}
	}
	else {
		bool allMatch;
		for (int i = 0; i < first->getTuplesSize(); i++) {
			allMatch = true;
			for (int j = 0; j < second->getTuplesSize(); j++) {
				allMatch = true;
				for (int k = 0; k < matching.size(); k++) {
					if (first->getTuple(i)->getAttribute(matching[k][0]) != second->getTuple(j)->getAttribute(matching[k][1])) {
						allMatch = false;
					}
					if (!allMatch)
						break;
				}
				if (allMatch) {
					t = new Tuple();
					for (int k = 0; k < first->getScheme()->getAttributeNames().size(); k++)
						t->addAttribute(first->getTuple(i)->getAttribute(k));
					for (int k = 0; k < second->getScheme()->getAttributeNames().size(); k++)
						t->addAttribute(second->getTuple(j)->getAttribute(k));
					r->addTuple(t);
				}
			}
		}
	}
	return r;
}

relation* relation::removeDups() {
	std::vector<Tuple*> newList;
	bool add = true;
	for (int i = 0; i < Tuples.size(); i++) {
		add = true;
		for (int j = 0; j < newList.size(); j++) {
			if (Tuples[i]->getAttributes() == newList[j]->getAttributes())
				add = false;
		}
		if (add) {
			Tuple* newTuple = new Tuple();
			newTuple->addAttributes(Tuples[i]->getAttributes());
			newList.push_back(newTuple);
		}
	}
	scheme* newScheme = new scheme();
	newScheme->addAttributeNames(rScheme->getAttributeNames());
	return new relation(name, newScheme, newList);
}

void relation::sortTuples() {

	std::vector< std::vector<std::string> > allStrings;
	for (int i = 0; i < Tuples.size(); i++)
		allStrings.push_back(Tuples[i]->getAttributes());
	std::sort(allStrings.begin(), allStrings.end(), std::less<std::vector<std::string>>());
	for (int i = 0; i < Tuples.size(); i++) {
		Tuples[i]->addAttributes(allStrings[i]);
	}
	return;
}

bool relation::compareTuples(const std::vector<std::string> &V1, const std::vector<std::string> &V2, int pos) {
	return V1[pos] < V2[pos];
}

void relation::clear() {
	delete rScheme;
	for (int i = 0; i < Tuples.size(); i++) {
		delete Tuples[i];
	}
	Tuples.clear();
	return;
}