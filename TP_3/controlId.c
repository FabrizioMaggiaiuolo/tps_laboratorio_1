#include <stdio.h>
#include <stdlib.h>


void CrearArchivoIds(void)
{

	int idInicial;
	idInicial = 1001;

	FILE* fileIds;
	fileIds = fopen("id.bin","wb");
	fwrite(&idInicial,sizeof(int),1,fileIds);

	fclose(fileIds);

}

int LeerIdInt(void)
{
	int id;

	FILE* fileIds;
	fileIds = fopen("id.bin","r");
	fread(&id,sizeof(int),1,fileIds);

	fclose(fileIds);

	return id;
}

void LeerIdStr(char* strId)
{
	int id;

	FILE* fileIds;
	fileIds = fopen("id.bin","r");
	fread(&id,sizeof(int),1,fileIds);

	fclose(fileIds);

	itoa(id,strId,10);
}

void SumarId(void)
{

	int id;
	id = LeerIdInt();

	id++;

	FILE* fileIds;
	fileIds = fopen("id.bin","wb");
	fwrite(&id,sizeof(int),1,fileIds);

	fclose(fileIds);
}
