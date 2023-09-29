#include <iostream>
#include <fstream>
#include <stdlib.h>
//#include <ofstream>
using namespace std;
//создание тектового файла структура файла в строке 1 число строка завершается симвовлом конца строки
void inpfiletxt(ofstream &fout, const char *namefile)
{
  fout.open(namefile, ios::out | ios::trunc);
  for (int x = 1; x <= 10; x++)
  {
    fout << x << endl;
  }
  fout.close();
}
//вывод содержимого тектового файла чтение числа и сивола конца строки чтобы обработать до конца файла
void outfiletxt( const char *namefile)
{
  int x;
  ifstream fin;
  cout << endl;
  fin.open(namefile, ios::in);
  while (!fin.eof())
  {
    fin >> x;
    fin.get();
    cout << x;
  }
  fin.close();
  
}
//добавление записи в конец файла
void appfiletxt(ofstream &fout, const char *namefile, int x)
{
  fout.open(namefile, ios::out |ios::app);
  fout << x;
  fout.close();
}
//прочитать запись по заданному номеру
void seekNtextfile( const char *namefile, int n)
{
  int x;
  ifstream fin;
  fin.open(namefile, ios::in);
  int i;
  for (i = 1; (i<n && (!fin.eof())); i++);
  {
    fin >> x;
    fin.get();
  }
  cout << endl;
  while (!fin.eof() && (i == n))
  {
    fin >> x;
    fin.get();
    cout << x;
    i++;
  }
  fin.close();
  
}
//количество чисел в файле
void utfiletext( const char *namefile)
{
  int n;
  n=0;

  int x;
  ifstream fin;
  cout << endl;
  fin.open(namefile, ios::in);
  while (!fin.eof())
  {
    fin >> x;
    fin.get();
    n++;
  }
  cout << "\n number of numbers = "<<n;
  fin.close();
  
}
//прочитать значение числа указав его порядковый номер в файле и вернуть его значение
void tfiletxt( const char *namefile)
{
  int i;
  i = 0;
  int x;
  ifstream fin;
  cout << endl;
  fin.open(namefile, ios::in);
  while (!fin.eof())
  {
    fin >> x;
    fin.get();
    cout << x;
    cout << "the consecutive number is "<< i << endl;
    i++;
  }
  fin.close();
  
}
int main()
{
  ofstream fout;
  inpfiletxt(fout, "A.txt");
  ifstream in_stream;

  ofstream f;
  f.open("A.txt");
  if (!f.is_open())
  {
    cout << "the file is not opened";

    return 1;
  }
  f.close();
  f.open("A.txt");
  if (!f.good())
  {
    cout << "seems something went wrong...";

    return 1;
  }
  f.close();
  in_stream.open( "A.txt");
  if ( in_stream.fail())
  {
    cout << "file opening error :(\n";
    exit(1);
  }
  ifstream fin;
  outfiletxt("A.txt");
  utfiletext("A.txt");
  appfiletxt(fout,"A.txt", 100);
  outfiletxt("A.txt");
  utfiletext("A.txt");
  tfiletxt("A.txt");
  seekNtextfile("A.txt", 4);
  cin.get();
  return 0;
}