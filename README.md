# Implementación del Modelo Harrison-Ruzzo-Ullman (HRU) en C++

## Descripción
Este código implementa una versión simplificada del **Modelo Harrison-Ruzzo-Ullman (HRU)**, que es un modelo de control de acceso que define cómo los sujetos (usuarios) interactúan con objetos (recursos) a través de permisos.

El programa utiliza una matriz de acceso representada por un mapa en C++, donde los sujetos tienen objetos asociados, y estos a su vez, tienen una lista de permisos. El programa permite agregar, modificar y eliminar sujetos, objetos y permisos de la matriz.

## Estructura de la Matriz de Acceso
La matriz de acceso está estructurada como:
- `map<string, map<string, vector<string>>> accessMatrix`: Un mapa donde:
  - La primera clave es un sujeto (usuario).
  - El valor asociado es otro mapa que relaciona objetos con un vector de permisos.

## Funcionalidades Principales

### 1. **Crear Sujeto**
- **Función:** `void createSubject(const string& subject)`
- Crea un nuevo sujeto (usuario) en la matriz de acceso.
- Si el sujeto ya existe, se muestra un mensaje indicando que ya está registrado.

### 2. **Crear Objeto**
- **Función:** `void createObject(const string& subject, const string& object)`
- Añade un objeto bajo un sujeto específico.
- Verifica si el objeto ya existe para evitar duplicados.

### 3. **Agregar Permiso**
- **Función:** `void addPermission(const string& subject, const string& object, const string& permission)`
- Asigna un permiso específico (por ejemplo, leer, escribir) a un sujeto sobre un objeto.
- Verifica si el permiso ya ha sido asignado antes de agregarlo.

### 4. **Eliminar Permiso**
- **Función:** `void removePermission(const string& subject, const string& object, const string& permission)`
- Elimina un permiso específico de un sujeto sobre un objeto.
- Si el permiso no existe, informa al usuario.

### 5. **Eliminar Sujeto**
- **Función:** `void deleteSubject(const string& subject)`
- Elimina completamente un sujeto y sus permisos asociados de la matriz de acceso.

### 6. **Eliminar Objeto**
- **Función:** `void deleteObject(const string& subject, const string& object)`
- Elimina un objeto bajo un sujeto específico de la matriz de acceso.

### 7. **Mostrar Matriz de Acceso**
- **Función:** `void displayMatrix() const`
- Muestra la estructura completa de la matriz de acceso: los sujetos, los objetos que controlan, y los permisos asociados.

## Ejemplo de Uso
El programa sigue los siguientes pasos en su ejecución:
1. Crear un sujeto llamado `Usuario1`.
2. Crear un objeto `Archivo1` bajo el sujeto `Usuario1`.
3. Agregar los permisos `leer` y `escribir` a `Usuario1` sobre `Archivo1`.
4. Mostrar la matriz de acceso.
5. Eliminar el permiso `escribir`.
6. Mostrar la matriz de acceso actualizada.
7. Eliminar el objeto `Archivo1`.
8. Mostrar la matriz de acceso.
9. Eliminar el sujeto `Usuario1`.
10. Mostrar la matriz vacía.

### Ejemplo en Código
```cpp
int main() {
    HRUModel hru;

    hru.createSubject("Usuario1");
    hru.createObject("Usuario1", "Archivo1");
    hru.addPermission("Usuario1", "Archivo1", "leer");
    hru.addPermission("Usuario1", "Archivo1", "escribir");

    cout << "Mostrando Matriz" << endl;
    hru.displayMatrix();

    hru.removePermission("Usuario1", "Archivo1", "escribir");
    cout << "Mostrando Matriz" << endl;
    hru.displayMatrix();

    hru.deleteObject("Usuario1", "Archivo1");
    cout << "Mostrando Matriz" << endl;
    hru.displayMatrix();

    hru.deleteSubject("Usuario1");
    cout << "Mostrando Matriz" << endl;
    hru.displayMatrix();

    return 0;
}
