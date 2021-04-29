#include "PolynomialList.h"
#include "RationalFraction.h"
#include "NotImplementedException.h"
#include <utility>
#include <module/n.h>

using namespace base;

PolynomialList *PolynomialList::lastElement() {
	PolynomialList* el = this;
	for(; el->next != nullptr; el = el->next);
	return el;
}

PolynomialList *PolynomialList::addElement(PolynomialList *element) {
	PolynomialList* el = this;

	for(; el != nullptr && module::COM_NN_D(element->degree, el->degree) != 2; el = el->next){
		element->prev = element->next;
		element->next = el;
	}
	if(el == nullptr){
		//todo
	}
}

PolynomialList* PolynomialList::operator[](const ULongNumber& index) {
	PolynomialList* el = this;
	// поиск можно реализовать через бинарный поиск и сделать его не O(n) а O(log2(n))
	for(; el != nullptr && el->degree != index; el = el->next);

	if(el == nullptr){
		el = new PolynomialList(index, RationalFraction::empty());
		addElement(el);
	}

	return el;
}
