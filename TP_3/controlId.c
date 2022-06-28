#include <stdio.h>
#include <stdlib.h>


void ArchivoIds(int id)
{
	FILE* fileIds;
	fileIds = fopen("id.bin","wb");
	fwrite(&id,sizeof(int),1,fileIds);

	fclose(fileIds);

}

int LeerIdInt()
{
	int id;

	FILE* fileIds;
	fileIds = fopen("id.bin","rb");
	fread(&id,sizeof(int),1,fileIds);

	fclose(fileIds);

	return id;
}

void LeerIdStr(char* strId)
{
	int id;

	FILE* fileIds;
	fileIds = fopen("id.bin","rb");
	fread(&id,sizeof(int),1,fileIds);

	fclose(fileIds);

	itoa(id,strId,10);
}

void SumarId()
{
	int id;

	id = LeerIdInt();

	id++;

	ArchivoIds(id);

}
