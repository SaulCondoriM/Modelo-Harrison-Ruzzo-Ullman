# Modelo Harrison-Ruzzo-Ullman (HRU)

## Introducción
El **Modelo de Harrison-Ruzzo-Ullman** (HRU) es un modelo formal propuesto en 1976 para gestionar y controlar los accesos en sistemas de información. Este modelo extiende los principios de la matriz de control de acceso, permitiendo la creación, modificación y eliminación de derechos de acceso dinámicamente a lo largo del tiempo.

## Elementos Clave del Modelo

### 1. **Matriz de Acceso**
- El HRU utiliza una **matriz de acceso** donde las filas representan **sujetos** (usuarios o procesos) y las columnas **objetos** (archivos, recursos).
- Cada celda de la matriz define los **derechos** que un sujeto tiene sobre un objeto, como leer, escribir, ejecutar, etc.

### 2. **Operaciones Básicas**
El modelo permite las siguientes operaciones:
- **Agregar** derechos.
- **Eliminar** derechos.
- **Transferir** derechos entre usuarios.
- **Crear** nuevos objetos y sujetos.
- **Eliminar** objetos y sujetos.

### 3. **Reglas de Transición**
- Las reglas de transición permiten modificar la matriz de acceso de acuerdo con las operaciones realizadas por los sujetos.
- Las reglas definen cómo pueden cambiar los derechos de acceso en respuesta a la creación, modificación o eliminación de sujetos y objetos.

## Aportaciones del Modelo

### 1. **Indecidibilidad de la Seguridad General**
Una de las principales conclusiones del modelo HRU es que, en su forma más general, es **indecidible** determinar si un sistema es completamente seguro, es decir, no se puede garantizar que un usuario no autorizado obtenga acceso a un recurso en todos los casos.

### 2. **Flexibilidad y Complejidad**
- El modelo es **dinámico** y **flexible**, lo que permite adaptarse a sistemas que cambian con el tiempo.
- Sin embargo, esta flexibilidad incrementa la **complejidad** del análisis de seguridad.

### 3. **Formalización del Control de Acceso**
El HRU proporciona una **formalización matemática** para la gestión de derechos de acceso, lo que facilita su análisis teórico y la verificación de políticas de seguridad.

## Limitaciones
- **Aplicabilidad Práctica**: Debido a su indecidibilidad, el HRU tiene limitaciones en la práctica, especialmente para sistemas muy complejos.
- **Simplicidad Teórica**: El HRU es más adecuado para estudios teóricos que para su implementación directa en sistemas reales.

## Conclusiones
- El modelo HRU es un **pilar fundamental** en el estudio teórico de la seguridad informática.
- A pesar de su **indecidibilidad**, establece las **bases formales** para entender las dinámicas de control de acceso.
- Es el punto de partida para otros modelos de seguridad más especializados y con aplicaciones más directas en entornos reales, como el modelo de Bell-LaPadula y Biba.
