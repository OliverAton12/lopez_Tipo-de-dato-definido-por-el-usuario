//fecha: 17/07/24
////Autor: Lopez Quiroz Wagner
//tema: Tipo de dato definido por el usuario

#include <iostream>
using namespace std;

// Estructura que representa un libro
struct Libro
{
    string codigo;  // Código del libro
    string titulo;  // Título del libro
    string autor;   // Autor del libro
    int precio;     // Precio del libro
};

// Función que asigna datos predeterminados a los libros
// Parámetros:
// - libros: Arreglo de libros donde se guardarán los datos
// - total: Número total de libros a asignar
void AsignarLibros(Libro libros[], int total)
{
    libros[0].codigo = "001";
    libros[0].titulo = "Un grito desesperado";
    libros[0].autor = "Carlos Cuauhtemoc Sánchez";
    libros[0].precio = 10;

    libros[1].codigo = "002";
    libros[1].titulo = "Las cruces sobre el agua";
    libros[1].autor = "Joaquín Gallegos Lara";
    libros[1].precio = 12;

    libros[2].codigo = "003";
    libros[2].titulo = "El Guaraguao";
    libros[2].autor = "Joaquín Gallegos Lara";
    libros[2].precio = 8;

    libros[3].codigo = "004";
    libros[3].titulo = "A la costa";
    libros[3].autor = "Luis A. Martínez";
    libros[3].precio = 11;

    // Agregar otros 3 libros
    libros[4].codigo = "005";
    libros[4].titulo = "Cien años de soledad";
    libros[4].autor = "Gabriel García Márquez";
    libros[4].precio = 15;

    libros[5].codigo = "006";
    libros[5].titulo = "Don Quijote de la Mancha";
    libros[5].autor = "Miguel de Cervantes";
    libros[5].precio = 20;

    libros[6].codigo = "007";
    libros[6].titulo = "La Odisea";
    libros[6].autor = "Homero";
    libros[6].precio = 18;
}

// Función que busca y asigna un libro por su código
// Parámetros:
// - libros: Arreglo de libros predeterminados
// - total: Número total de libros predeterminados
// - codigo: Código del libro a buscar
// Retorna:
// - El libro encontrado o un libro vacío si no se encuentra el código
Libro BuscarLibroPorCodigo(Libro libros[], int total, string codigo)
{
    for(int i = 0; i < total; i++)
    {
        if(libros[i].codigo == codigo)
        {
            return libros[i];
        }
    }

    return {"", "", "", 0}; // Retornar libro vacío si no se encuentra
}

// Función que permite ingresar los códigos de los libros por teclado
// y asigna los demás datos automáticamente
// Parámetros:
// - libros: Arreglo de libros donde se guardarán los datos ingresados
// - total: Número total de libros a ingresar
void IngresarLibrosPorCodigo(Libro libros[], int total)
{
    const int MAX_PREDETERMINADOS = 7;
    Libro librosPredeterminados[MAX_PREDETERMINADOS];
    AsignarLibros(librosPredeterminados, MAX_PREDETERMINADOS);

    for(int i = 0; i < total; i++)
    {
        string codigo;
        cout << "Ingrese el código del libro " << i + 1 << ": ";
        cin >> codigo;

        Libro libroEncontrado = BuscarLibroPorCodigo(librosPredeterminados, MAX_PREDETERMINADOS, codigo);

        if (libroEncontrado.codigo == "")
        {
            cout << "Código no encontrado. Intente de nuevo." << endl;
            i--; // Retroceder el índice para volver a ingresar
        }
        else
        {
            libros[i] = libroEncontrado;
            cout << "Libro asignado: " << libros[i].titulo << " por " << libros[i].autor << " ($" << libros[i].precio << ")" << endl;
        }

        cout << "------------------------" << endl;
    }
}

// Función que imprime los datos de los libros
// Parámetros:
// - libros: Arreglo de libros cuyos datos se imprimirán
// - total: Número total de libros a imprimir
void ImprimirLibros(Libro libros[], int total)
{
    for(int k = 0; k < total; k++)
    {
        cout << "Código: " << libros[k].codigo << endl;
        cout << "Título: " << libros[k].titulo << endl;
        cout << "Autor: " << libros[k].autor << endl;
        cout << "Precio: $" << libros[k].precio << endl;
        cout << "------------------------" << endl;
    }
}

// Función que ordena los libros por título en orden ascendente
// Parámetros:
// - libros: Arreglo de libros a ordenar
// - total: Número total de libros en el arreglo
void OrdenarxTitulo(Libro libros[], int total)
{
    for(int i = 0; i < total - 1; i++)
    {
        for(int j = 0; j < total - i - 1; j++)
        {
            if(libros[j].titulo > libros[j + 1].titulo)
            {
                Libro temp = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = temp;
            }
        }
    }
}

// Función que ordena los libros por precio de mayor a menor
// Parámetros:
// - libros: Arreglo de libros a ordenar
// - total: Número total de libros en el arreglo
void OrdenarxPrecio(Libro libros[], int total)
{
    for(int i = 0; i < total - 1; i++)
    {
        for(int j = 0; j < total - i - 1; j++)
        {
            if(libros[j].precio < libros[j + 1].precio)
            {
                Libro temp = libros[j];
                libros[j] = libros[j + 1];
                libros[j + 1] = temp;
            }
        }
    }
}

// Función principal del programa
int main()
{
    const int MAX = 7; // Número máximo de libros
    Libro libros[MAX];
    int opcion;

    cout << "Elija una opción: " << endl;
    cout << "1. Asignar libros automáticamente" << endl;
    cout << "2. Ingresar libros por código" << endl;
    cin >> opcion;

    if (opcion == 1)
    {
        AsignarLibros(libros, MAX);
    }
    else if (opcion == 2)
    {
        IngresarLibrosPorCodigo(libros, MAX);
    }
    else
    {
        cout << "Opción no válida" << endl;
        return 1;
    }

    ImprimirLibros(libros, MAX);

    cout << endl << "Ordenando por título..." << endl;
    OrdenarxTitulo(libros, MAX);
    ImprimirLibros(libros, MAX);

    cout << endl << "Ordenando por precio de mayor a menor..." << endl;
    OrdenarxPrecio(libros, MAX);
    ImprimirLibros(libros, MAX);

    cout << endl << "Tipo estructurado";

    return 0;
}
