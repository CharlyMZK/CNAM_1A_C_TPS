
typedef struct sFileNoeud
{
	void* val;
	struct sFileNoeud* next;
} FileNoeud;
	

typedef struct
{
	 FileNoeud* first;
	 FileNoeud* last;
} File;


FileNoeud* nouveau_noeud(void* v);

File* file_vide();

void* defile(File* fi);

int est_file_vide(File* fi);

void enfile(File* l, void* ptr);



