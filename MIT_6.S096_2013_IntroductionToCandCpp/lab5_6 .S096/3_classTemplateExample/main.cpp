
#include <stdio.h>	

template <class T>
class mypair{
	T a, b;
public:
	mypair(T first, T second){
	a=first;
	b=second;
	}
	T getmax();
};

template <class T>
T mypair<T>::getmax(){
	return a>b ? a:b;
}

int main(){
       mypair<int> myints(100,75);
       printf("%d\n", myints.getmax());
}       

