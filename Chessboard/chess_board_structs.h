
typedef struct player
{
	char name[20];	
	int number;
	char color[5];
} PLAYER;

typedef struct position
{
	char row;
	int column;
} POSITION;

typedef struct piece
{
	char name[20];
	PLAYER plOwner;
	POSITION pcPos;
} PIECE;

typedef struct tile
{
	int check; 		//occupy indicator
	char color[6];	
	PIECE pcType;
	POSITION pcPos;
} TILE;

typedef struct playerInfo
{
	PLAYER plInfo;
	PIECE plPieces[16];
	int available;
} PLINFO;

typedef struct chessboard
{
	TILE tile[8][8];
} CHESSBOARD;

