#include "PolynomialList.h"
#include "RationalFraction.h"
#include "NotImplementedException.h"
#include <utility>
#include <module/n.h>

using namespace base;

PolynomialList::PolynomialList(ULongNumber degree, RationalFraction value) : degree(std::move(degree)), value(std::move(value)), prev(nullptr), next(nullptr) {}

PolynomialList *PolynomialList::lastElement() {
	PolynomialList* el = this;
	for(; el->next != nullptr; el = el->next);
	return el;
}

PolynomialList *PolynomialList::addElement(PolynomialList *element) {
	PolynomialList* el = this;

	// ищем элемент, который имеет степень меньше или равно чем element
	for(; el != nullptr && module::COM_NN_D(element->degree, el->degree) != 2; el = el->next){
		element->prev = element->next;
		element->next = el;
	}

	// если у element самая старшая степень
	if(el == nullptr){
        element->prev = element->next; // тот самый предыдущий последний элемент
        element->next = nullptr;
	}else if(element->prev == nullptr){
	    return element;
	}

	return this;
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