int main() {
    int fd;
    char *line = NULL;

    // Abre un archivo para obtener un descriptor de archivo válido
    fd = open("test.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error abriendo el archivo");
        return 1;
    }

    // Llama a tu función gnl con el descriptor de archivo válido y un puntero a texto NULL
    char *result = get_next_line(fd);

    // Maneja el resultado de la llamada a gnl
    if (result == NULL) {
        perror("Error en gnl");
    } else {
        printf("Línea leída: %s\n", line);
    }

    // Libera la memoria y cierra el archivo
    free(line);
    close(fd);

    return 0;
}
