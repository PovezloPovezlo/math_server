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

	}
}

PolynomialList*& PolynomialList::operator[](const ULongNumber& index) {
	PolynomialList* el = this;
	for(; el != nullptr && el->value != index; el = el->next);

	if(el == nullptr){
		addElement(new PolynomialList(index, RationalFraction::empty()));
	}
}
