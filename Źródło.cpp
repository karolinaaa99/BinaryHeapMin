#include <iostream>

using namespace std;

class Heap
{
	private:
		int* kopiec; //tablica dynamiczna przechowujaca elementy kopca
		int capacity; //maksymalny rozmiar tablicy (kopca)
		int heap_size; //liczba elementow w tablicy, czyli liczna elementow kopca
	public:
		Heap(int c); //konstruktor, tworzy pusty kopiec o pojemnosci c
		Heap(); //konstruktor do testow kopca - nalezy utworzyc kopiec z nast. zawartoscia: 1,2,3,5,7,9,10,9,9,12
		bool empty(); //zwraca true, jesli kopiec jest pusty, false w przeciwnym razie
		bool full(); //zwraca true, jesli kopiec jest pelny, false w przeciwnym razie
		int left(int i); //zwraca pozycje lewego syna
		int right(int i); //zwraca pozycje prawego syna
		int parent(int i); //zwraca pozycje ojca
		int getSize(); //zwraca rozmiar kopca
		void setHeapSize(int s); //ustawia rozmiar kopca
		int get(int i); //zwraca wartosc z pozycji i
		void set(int i, int x); //na pozycji i ustawia wartosc x
		void up(int i); //przywraca wlasnosc kopca metoda wynurzania
		void down(int i); //przywraca wlasnosc kopca metoda zatapiania
		friend ostream& operator<<(ostream& out, Heap& h); //wyswietla kopiec na ekranie
};

Heap::Heap(int c)
{
	kopiec = new int[c];
	capacity = c;
	heap_size = 0;
}

Heap::Heap()
{
	capacity = 20;
	kopiec = new int[capacity] {1, 2, 3, 5, 7, 9, 10, 9, 9, 12};
	heap_size = 10;
}

bool Heap::empty()
{
	if (heap_size == 0)
		return true;
	else
		return false;
}

bool Heap::full()
{
	if (heap_size == capacity)
		return true;
	else
		return false;
}

int Heap::left(int i)
{
	if (!empty())
		return 2 * i + 1;
	else
		return NULL;
}

int Heap::right(int i)
{
	if (!empty())
		return 2 * i + 2;
	else
		return NULL;
}

int Heap::parent(int i)
{
	//jesli i jest korzeniem to nie ma ojca
	if (!empty())
	{
		if ((i - 1) / 2 >= 0 && i < heap_size)
			return (i - 1) / 2;
		else
			return NULL;
	}
	else
		return NULL;
}

int Heap::getSize()
{
	return heap_size;
}

void Heap::setHeapSize(int s)
{
	heap_size = s;
}

int Heap::get(int i)
{
	if (!empty())
	{
		if (i >= 0 && i < heap_size)
			return kopiec[i];
		else
			return NULL;
	}
	else
		return NULL;
}

void Heap::set(int i, int x)
{
	kopiec[i] = x;
}

void Heap::up(int i) //i to pozycja, od ktorej zaczynamy wynurzanie
{
	int wartosc_na_pozycji_i;
	int pozycja_ojca_i;
	int wartosc_ojca_i;

	wartosc_na_pozycji_i = get(i);
	pozycja_ojca_i = parent(i);
	wartosc_ojca_i = get(pozycja_ojca_i);

	if (i > 0 && wartosc_ojca_i > wartosc_na_pozycji_i)
	{
		swap(kopiec[pozycja_ojca_i], kopiec[i]);
		up(pozycja_ojca_i); //rekurencja
	}
}

void Heap::down(int i) //i to pozycja, od której zaczynamy zatapianie kopca
{
	int pozycja_lewego_syna;
	int pozycja_prawego_syna;
	int temp;

	pozycja_lewego_syna = left(i);
	pozycja_prawego_syna = right(i);
	temp = i;

	if (get(pozycja_lewego_syna) < get(i) && pozycja_lewego_syna < heap_size)
		temp = pozycja_lewego_syna;
	if (get(pozycja_prawego_syna) < get(temp) && pozycja_prawego_syna < heap_size)
		temp = pozycja_prawego_syna;

	if (temp != i)
	{
		swap(kopiec[i], kopiec[temp]);
		down(temp); //rekurencja
	}
}

ostream& operator<<(ostream& out, Heap& h)
{
	if (h.empty())
		return out;
	for (int i = 0; i < h.heap_size; i++)
	{
		out << h.kopiec[i] << " ";
	}
	return out;
}

int main()
{
	Heap kopiec = Heap();

	cout << kopiec << endl;

	kopiec.set(8, 4);

	kopiec.up(8);

	cout << kopiec << endl;

	kopiec.set(0, 15);

	kopiec.down(0);

	cout << kopiec << endl;

	return 0;
}