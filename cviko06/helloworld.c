#include <stdio.h>
#include <string.h>

#define DLZKA_TAGU 128
#define TITUL_OFFSET 3
#define AUTOR_OFFSET 30+TITUL_OFFSET

int main(void)
{
	FILE *subor = fopen("music.mp3","r");
	/* +1 je tam kvoli znaku konca stringu */
	char tag[DLZKA_TAGU+1];
	char buf[30+1];

	if(subor==NULL)
	{
		perror("Subor sa nepodarilo otvorit.");
		return -1;
	}

	/* postavi nas na 128.poziciu od konca */
	fseek(subor, -DLZKA_TAGU, SEEK_END);

	/* nacitame poslednych 128 znakov */
	fgets(tag, DLZKA_TAGU+1,subor);

	if(!(tag[0]=='T' && tag[1]=='A' && tag[2]=='G'))
	{
		perror("Subor nema tag.");
		return -2;
	}

	/* skopirujem si z tagu do buf */
	strncpy(buf, tag + TITUL_OFFSET, 30);
	printf("Nazov skladby je: %s\n",buf);
	strncpy(buf, tag + AUTOR_OFFSET, 30);
	printf("Autor je: %s\n",buf);

	memset(buf, '\0', sizeof(char)*31);
	fclose(subor);

	return 0;
}
