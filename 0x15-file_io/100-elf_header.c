#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * isElfFile - Checks if a file is an ELF file.
 * @file_d: File descriptor of the open file being checked.
 *
 * Description: This function takes a file descriptor as a parameter and checks
 * if the file associated with the file descriptor is an ELF file. It does this
 * by reading the ELF identification section from the file using the file
 * descriptor.
 * - If the file is not an ELF file, it returns 0 (indicating not an ELF file).
 * - If the file is an ELF file, it returns 1 (indicating it's an ELF file).
 *
 * Return: 1 if the file is an ELF file, 0 otherwise.
 */
int isElfFile(int file_d)
{
	unsigned char e_ident[EI_NIDENT];

	if (read(file_d, e_ident, EI_NIDENT) == -1)
	{
	perror("read");
	exit(98);
	}

	for (int i = 0; i < EI_MAG3; i++)
	{
	if (e_ident[i] != ELFMAG[i])
	{
		return (0);
	}
}

	return (1);
}

/**
 * displayElfHeader - Displays the ELF header information
 * @header: Pointer to an Elf64_Ehdr structure containing
 * the ELF header data.
 *
 * Description: This function prints various fields of
 * the ELF header to the standard output.
 */
void displayElfHeader(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf("  Magic: ");

	for (int index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x ", header->e_ident[index]);
	}

	printf("\n");
	printf("  Class: %s\n", (header->e_ident[EI_CLASS] == ELFCLASS64)
	? "ELF64" : "ELF32");
	printf("  Data: %s\n", (header->e_ident[EI_DATA] == ELFDATA2LSB) ?
	"2's complement, little endian" : "Unknown");
	printf("  Version: %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("  Type: %d\n", header->e_type);
	printf("  Entry point address: %#lx\n", header->e_entry);
}

/**
 * main - Displays information contained in the ELF
 * header at the start of an ELF file.
 * @argc: The count of arguments supplied to the program.
 * @argv: Array of pointers to the args in the program.
 * file_d - file descriptor
 * isElfFile - Checks is it is elf file
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 * on failure - exit code 98.
 */

int main(int argc, char *argv[])
{
Elf64_Ehdr elfHeader;

	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
	exit(98);
	}

int file_d = open(argv[1], O_RDONLY);

	if (file_d == -1)
	perror("open");
	exit(98);
}

	if (!isElfFile(file_d))
{
	fprintf(stderr, "Error: Not an ELF file\n");
	close(file_d);
	exit(98);
}

	if (read(file_d, &elfHeader, sizeof(Elf64_Ehdr)) == -1)
{
	perror("read");
	close(file_d);
	exit(98);
}

	displayElfHeader(&elfHeader);

	close(file_d);
	return (0);
}
