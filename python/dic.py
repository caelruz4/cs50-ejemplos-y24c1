import pandas as pd

# Función para agregar una canción a la playlist
def agregar_cancion(playlist):
    titulo = input("Ingresa el título de la canción: ")
    autor = input("Ingresa el nombre del autor de la canción: ")
    puntaje = float(input("Ingresa el puntaje de la canción (0-10): "))

    # Cada cancion es un diccionario
    cancion = {"titulo": titulo, "autor": autor, "puntaje": puntaje}
    playlist.append(cancion)
    print(f"Canción '{titulo}' agregada a la playlist.")

# Función para ver la playlist
# def ver_playlist(playlist):
#     print("Playlist:")
#     # for index, cancion in enumerate(playlist, start=1):
#     #     print(f"{index}. Título: {cancion['titulo']}, Autor: {cancion['autor']}, Puntaje: {cancion['puntaje']}")

#     for cancion in playlist:
#             print(f"Título: {cancion['titulo']}, Autor: {cancion['autor']}, Puntaje: {cancion['puntaje']}")

def ver_playlist(playlist):
    print("Playlist:")
    df = pd.DataFrame(playlist)
    print(df)

# Función para actualizar el puntaje de una canción
def actualizar_puntaje(playlist, titulo, nuevo_puntaje):
    for cancion in playlist:
        if cancion["titulo"] == titulo:
            cancion["puntaje"] = nuevo_puntaje
            print(f"Puntaje de la canción '{titulo}' actualizado a {nuevo_puntaje}.")
            return
    print(f"No se encontró la canción '{titulo}' en la playlist.")

# Función principal para manejar las opciones
def menu():
    playlist = []
    while True:
        print("\n¿Qué deseas hacer?")
        print("1. Agregar una canción")
        print("2. Ver la playlist")
        print("3. Actualizar puntaje de una canción")
        print("4. Salir")
        
        opcion = input("Selecciona una opción: ")

        if opcion == "1":
            agregar_cancion(playlist)
        elif opcion == "2":
            ver_playlist(playlist)
        elif opcion == "3":
            titulo = input("Ingresa el título de la canción que deseas actualizar: ")
            nuevo_puntaje = float(input("Ingresa el nuevo puntaje para la canción (0-10): "))
            actualizar_puntaje(playlist, titulo, nuevo_puntaje)
        elif opcion == "4":
            print("Saliendo del programa...")
            break
        else:
            print("Opción no válida. Por favor, selecciona una opción válida.")

# Llamada a la función principal
menu()
