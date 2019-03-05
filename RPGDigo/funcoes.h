void teleporte (int *warp, int *numeroMapa, int *posPlayerY, int *posPlayerX);
void maps (int mapa[][Tmap], char nomeMapa[], int *numeroMapa, int *inicio, int *posPlayerY, int *posPlayerX);
void imprimeMap (int mapa[][Tmap], char nomeMapa[], int *numeroMapa, int *posPlayerY, int *posPlayerX);
void comandoMovimento (int map2[][Tmap], int *y, int *x, bool *flagAnda, int **warp);
void comandoPlayer (int mapa[][Tmap], int *posPlayerY, int *posPlayerX, int *numeroMapa, int *warp, bool *andou);
void game ();
void sorteioMobAnda (bool *andou, int *numeroMapa, int *idMob);
void battle (int *idMob, char *playerNome, int *playerLevel, int *playerHp, int *playerExp, int *playerAtk, int *playerDef, int *playerAtkM, int *playerDefM);
void mob (int **idMob, char *mobNome, int *mobHp, int *mobExp, int *mobAtk, int *mobDef, int *mobAtkM, int *mobDefM);
