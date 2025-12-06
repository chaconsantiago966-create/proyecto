# proyecto
Proyecto de Juan José Triviño, Juan Esteban Espinoza, Santiago Chacón

Este proyecto es una aplicación de escritorio que permite a un usuario registrar y consultar sus indicadores básicos de salud: peso, presión arterial y glucosa.
Fue desarrollada en C++, utilizando Qt para la interfaz gráfica y SQLite como base de datos local.

El sistema permite:

  Iniciar sesión con usuario y contraseña
  Registrar nuevos datos de salud
  Visualizar el historial filtrado por fechas
  Calcular estadísticas básicas
  Exportar registros a CSV
  Manejar la información de forma segura y organizada

Este proyecto fue creado como entrega final para la asignatura Algoritmos en Sistemas Electrónicos.

Características principales

  Autenticación de usuarios
  CRUD de registros de salud
  Base de datos local SQLite
  Interfaz gráfica con Qt Widgets
  Cálculo de estadísticas básicas
  Exportación de datos a CSV
  Diseño orientado a objetos

Tecnologías utilizadas

  Lenguaje: C++
  Framework: Qt5 / Qt6 (según instalación)
  Base de datos: SQLite
  Entorno: Linux (compatible con Windows si se recompila)

  Estructura del proyecto
  
  proyecto-rastreador-salud/
├─ src/
│  ├─ main.cpp
│  ├─ loginwindow.cpp
│  ├─ mainwindow.cpp
│  ├─ user.cpp
│  ├─ healthrecord.cpp
│  ├─ databasemanager.cpp
│  ├─ healthanalyzer.cpp
│  ├─ csvexporter.cpp
│  └─ ...
├─ include/
│  ├─ loginwindow.h
│  ├─ mainwindow.h
│  ├─ user.h
│  ├─ healthrecord.h
│  ├─ databasemanager.h
│  ├─ healthanalyzer.h
│  ├─ csvexporter.h
├─ ui/
│  ├─ loginwindow.ui
│  └─ mainwindow.ui
├─ sql/
│  └─ init_db.sql
├─ data/
│  └─ health_tracker.db
├─ docs/
│  ├─ informe_proyecto.pdf
│  └─ presentacion.pptx
└─ README.md

Base de datos

El proyecto utiliza una base SQLite con dos tablas:
users
| Campo         | Tipo   | Descripción        |
| ------------- | ------ | ------------------ |
| id            | INT PK | Identificador      |
| username      | TEXT   | Nombre de usuario  |
| password_hash | TEXT   | Contraseña en hash |

health_records
| Campo     | Tipo   | Descripción                |
| --------- | ------ | -------------------------- |
| id        | INT PK | Identificador del registro |
| user_id   | INT FK | Usuario propietario        |
| weight    | REAL   | Peso                       |
| systolic  | INT    | Presión sistólica          |
| diastolic | INT    | Presión diastólica         |
| glucose   | REAL   | Nivel de glucosa           |
| timestamp | TEXT   | Fecha y hora del registro  |

Funcionalidades principales de la aplicación

➤ Login
Permite autenticación básica y validación de contraseña.

➤ Registro de datos
Formulario para ingresar peso, presión arterial y glucosa.

➤ Historial
Tabla filtrable por rango de fechas.

➤ Estadísticas
Promedios básicos calculados automáticamente.

➤ Exportación CSV
Exporta los registros del usuario a un archivo .csv descargable.

Mejoras futuras

  Añadir más indicadores de salud (IMC, frecuencia cardiaca, etc.)
  Notificaciones y alertas
  Sincronización con la nube
  Versión móvil o web
  Gráficas más avanzadas

  Autores

Juan José Triviño, Juan Esteban Espinoza, Santiago Chacón
Estudiantes de Algoritmos en Sistemas Electrónicos
Universidad Escuela Colombiana de Ingeniería.

  
