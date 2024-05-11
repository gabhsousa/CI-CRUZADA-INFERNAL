#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <locale.h>

#define limparBufferEntrada() while(getchar() != '\n')

typedef enum{
    ZUMBI,
    ESQUELETO,
    BOSS
} classe;

typedef struct {
    char nome[10];
    int hp;
    int hpmax;
    int mp;
    int mpmax;
    int potionhp;
    int potionmp;
    int forca;
    int inteligencia;
    int destreza;
} Character;

typedef struct {
    char nome[20];
    int hp;
    int hpmax;
    int mp;
    int mpmax;
    int destreza;
    classe classe_ene;
} Enemy;

void clear_screen() {
    system("cls");
}

void display_stats(Character *player, Enemy *enemy) {
    printf("_________________________________________\n");
    printf("|  ____________            ____________ |\n");
    printf("|  |hp:%3d/%3d|            |hp:%3d/%3d| |\n", player->hp, player->hpmax, enemy->hp, enemy->hpmax);
    printf("|  |mp:%3d/%3d|            |mp:%3d/%3d| |\n", player->mp, player->mpmax, enemy->mp, enemy->mpmax);
    printf("|   ----------              ----------  |\n");
    printf("|                                       |\n");
}

void display_commands() {                                  
    printf("|_______________________________________|\n");             
    printf("|         |         |         |         |\n");
    printf("|1-ATACAR |2-SKILLS |3-DEFESA |4-ITENS  |\n");
    printf("|_________|_________|_________|_________|\n");
}

char display_skills(int v_desejado , Character *princ) {
	while(1){
		switch (v_desejado){
            case 2 :
                printf("_________________________________________\n");
                printf("|         |         |         |         |\n");
                printf("|1-PWRATK |2-ECOATK |3-HITKILL|4-VOLTAR |\n");
                printf("|_________|_________|_________|_________|\n");
                char input = getch();
                switch (input){
                    case '1':
					if(princ->mp >= 10){
                        return 'a';
					}
					else{
						return 'l';
					}
                    case '2':
					if(princ->mp >= 20){
                        return 'b';
					}
					else {
						return 'l';
					}

                    case '3':
					if(princ->mp >= 25){
                        return 'c';
					}else{
						return 'l';
					}

                    case '4':
                        return 'v';
                    default:
                        break;
                }
            case 4 :
                printf("_________________________________________\n");
                printf("|         |         |         |         |\n");
                printf("|1-Poção  |2-Poção  |         |4-VOLTAR |\n");
                printf("| HP x %2d | MP x %2d |         |         |\n", princ->potionhp, princ->potionmp);
                printf("|_________|_________|_________|_________|\n");
                input = getch();
                switch (input){
                    case '1':
						if(princ->potionhp >= 1){
						princ->potionhp--;
                        return 'd';
						}
						else{
						return 'm';
						}
						
                    case '2':
						if(princ->potionmp >= 1){
						princ->potionmp--;						
                        return 'e';
						}
						else{
						return 'm';
						}
                    case '4':
                        return 'v';
                    default:
                        break;
                } 
        }  
	}
}

void display_info(char stats[38]){
    printf("_________________________________________\n");
    printf("|%-39s|\n",stats);
    printf("-----------------------------------------\n");
}

void sprite_mc(int estado,int estado_2){
            switch(estado){
                case 1:
					switch(estado_2){
                    case 1:
					printf("|  O                 ");
					return;
					case 2:
                    printf("| /|\\|               ");
					return;
					case 3:
                    printf("| / \\                ");
					return;	
                    }

                case 2:
	                switch(estado_2){
					case 1:
                    printf("|          O         ");
					return;
					case 2:
                    printf("|         /|\\/       ");
					return;
					case 3:
                    printf("|         / \\        ");
					return;
                    }
                case 3:
					switch(estado_2){
					case 1:
                    printf("|               O    ");
					return;
				    case 2:
                    printf("|              /|\\__ ");
					return;
					case 3:
                    printf("|              / \\   ");
					return;			
				}
            }
    }

void sprite_enemy(Enemy *ene, int estado,int estado_2){
    switch(ene->classe_ene){
        case ZUMBI:
            switch(estado){
                case 1:
					switch(estado_2){
					case 1:
                    printf("                O  |\n");
					return;
					case 2:                
                    printf("               /|  |\n");
					return;
					case 3:	
                    printf("                 \\ |\n");
					return;
                   }
                case 2:
					switch(estado_2){
	                case 1:
                    printf("           O       |\n");
					return;
                    case 2:
					printf("          /|       |\n");
					return;
					case 3:
                    printf("            \\      |\n");
                    return;
                    }
                case 3:
					switch(estado_2){
		            case 1:
                    printf("  __O              |\n");
					return;
                    case 2:
                    printf("    |              |\n");
                    return;
                    case 3:
					printf("     \\             |\n");
					return;
                    }
				}
        case ESQUELETO:
            switch(estado){
                case 1:
					switch(estado_2){
					case 1:
                    printf("              0    |\n");
					return;
					case 2:
                    printf("            {|/|)  |\n");
					return;
					case 3:
                    printf("              / \\  |\n");
                    return;
				}
                case 2:
					switch(estado_2){
					case 1:
                    printf("               0   |\n");
					return;
					case 2:
                    printf("      <-    (|/|)  |\n");
					return;
					case 3:
                    printf("              / \\  |\n");
                    return;
				}
                case 3:
					switch(estado_2){
					case 1:
                    printf("               0   |\n");
					return;
					case 2:
                    printf("<-          (|/|)  |\n");
					return;
					case 3:
                    printf("              / \\  |\n");
                    return;;
            	}
			}

        case BOSS:
            switch(estado){
                case 1:
					switch(estado_2){
					case 1:
                    printf("               O   |\n");
					return;
					case 2:
                    printf("             l/|\\  |\n");
					return;
					case 3:
                    printf("              / \\  |\n");
                    return;
				}
                case 2:
					switch(estado_2){
					case 1:
                    printf("               O   |\n");
					return;
					case 2:
                    printf("      *      l/|\\  |\n");
					return;
					case 3:
                    printf("              / \\  |\n");
                    return;
				}
                case 3:
					switch(estado_2){
					case 1:
                    printf("               O   |\n");
					return;
					case 2:
                    printf("*            l/|\\  |\n");
					return;
					case 3:
                    printf("              / \\  |\n");
                    return;
				}
            }
        break;
    }
}

int ataque(int porcentagem) {
    int chance = rand() % (100 - porcentagem);

    if (chance < porcentagem){
        return 0;
    }else{
        return 1;
    }

}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Character player = {"",100, 100, 50, 50,8,8,20,5,13};
    Enemy enemy = {"Morto Vivo",100, 100, 15, 30,30,ZUMBI};
	Enemy enemy2 ={"Esqueleto Arqueiro",80,80,10,30,30,ESQUELETO};
	Enemy boss ={"Makson",200,200,20,50,50,BOSS};
    char input = 0;
	int defendeu = 0;

	printf("No mundo de lucaf, todos os jovens após completarem 18 anos partem para uma jornada em busca de gloria...\n");
    Sleep(4000);
	printf("Enfrentano monstros terriveis e provações complexas, eles se aventuram em busca de significado na sua vida...\n");
	Sleep(4000);
    printf("esse é a jornada é conhecida por todos como Cruzada Infernal!\n");
	Sleep(5000);	
	while(1){
	clear_screen();
	printf("   ####   ######   ##   ##  #######    ##     #####      ##\n");
	Sleep(500);
	printf("  ##  ##   ##  ##  ##   ##  #   ##    ####     ## ##    ####\n");
    Sleep(500);
    printf(" ##        ##  ##  ##   ##     ##    ##  ##    ##  ##  ##  ##\n");
	Sleep(500);
	printf(" ##        #####   ##   ##    ##     ##  ##    ##  ##  ##  ##\n");
	Sleep(500);
	printf(" ##        ## ##   ##   ##   ##      ######    ##  ##  ######\n");
	Sleep(500);
	printf("  ##  ##   ##  ##  ##   ##  ##    #  ##  ##    ## ##   ##  ##\n");
	Sleep(500);
	printf("   ####   #### ##   #####   #######  ##  ##   #####    ##  ##\n");
	Sleep(500);
	printf("\n");
	Sleep(500);
	printf("        ####    ##   ##  #######  #######  ######   ##   ##    ##     ####\n");
	Sleep(500);
	printf("         ##     ###  ##   ##   #   ##   #   ##  ##  ###  ##   ####     ##\n");
	Sleep(500);
	printf("         ##     #### ##   ## #     ## #     ##  ##  #### ##  ##  ##    ##\n");
	Sleep(500);
	printf("         ##     ## ####   ####     ####     #####   ## ####  ##  ##    ##\n");
	Sleep(500);
	printf("         ##     ##  ###   ## #     ## #     ## ##   ##  ###  ######    ##   #\n");
	Sleep(500);
	printf("         ##     ##   ##   ##       ##   #   ##  ##  ##   ##  ##  ##    ##  ##\n");
	Sleep(500);
	printf("        ####    ##   ##  ####     #######  #### ##  ##   ##  ##  ##   #######\n\n");
	Sleep(500);
	printf("Aperte qualquer tecla para começar.");
	input=getch();

	if(input != ' '){
	break;
    }
	
    }
	clear_screen();
    printf("Digite seu Nome: ");
    scanf("%s" ,player.nome);

    while (player.hp > 0 && enemy.hp > 0) {
		
        if (player.mp < 0){
		player.mp = 0;
        }
		display_info("");
        display_stats(&player, &enemy);
			sprite_mc(1,1);                       //Sprite 1 do jogador e do inimigo (repouso)
			sprite_enemy(&enemy,1,1);
			sprite_mc(1,2);
			sprite_enemy(&enemy,1,2);
			sprite_mc(1,3);
			sprite_enemy(&enemy,1,3);
			display_commands();
	        input = getch();

		if(input == '1'){
        	if(ataque(-enemy.destreza)==1){
				Sleep(500);
				clear_screen();
			        char acao[38] = {""};
			        strcpy(acao, player.nome);
			        strcat(acao, " atacou!");
				        display_info(acao);
						display_stats(&player, &enemy);    
						sprite_mc(2,1);            //Sprite 2 do jogador
						sprite_enemy(&enemy,1,1);
						sprite_mc(2,2);
						sprite_enemy(&enemy,1,2);
						sprite_mc(2,3);
						sprite_enemy(&enemy,1,3);
						display_commands();
							Sleep(500);
							clear_screen();
					enemy.hp -= player.forca;
				        display_info(acao);
						display_stats(&player, &enemy);
						sprite_mc(3,1);             //Sprite 3 do jogador
						sprite_enemy(&enemy,1,1);
						sprite_mc(3,2);
						sprite_enemy(&enemy,1,2);
						sprite_mc(3,3);
						sprite_enemy(&enemy,1,3);
						display_commands();
							Sleep(500);
							clear_screen();          
        			}else{
						Sleep(500);
						clear_screen();
					        char acao[38] = {""};
					        strcpy(acao, player.nome);
					        strcat(acao, " atacou, Mas errou!");
						        display_info(acao);
								display_stats(&player, &enemy);    
								sprite_mc(2,1);            //Sprite 2 do jogador
								sprite_enemy(&enemy,1,1);
								sprite_mc(2,2);
								sprite_enemy(&enemy,1,2);
								sprite_mc(2,3);
								sprite_enemy(&enemy,1,3);
								display_commands();
									Sleep(500);
									clear_screen();
						        display_info(acao);
								display_stats(&player, &enemy);
								sprite_mc(3,1);             //Sprite 3 do jogador
								sprite_enemy(&enemy,1,1);
								sprite_mc(3,2);
								sprite_enemy(&enemy,1,2);
								sprite_mc(3,3);
								sprite_enemy(&enemy,1,3);
								display_commands();
									Sleep(500);
									clear_screen();   
        						}
        					}
							else if (input == '2'){
							    clear_screen();
								display_stats(&player, &enemy);
								sprite_mc(1,1);                       //Tela de Habilidades (repouso)
								sprite_enemy(&enemy,1,1);
								sprite_mc(1,2);
								sprite_enemy(&enemy,1,2);
								sprite_mc(1,3);
								sprite_enemy(&enemy,1,3);
									int special = display_skills(2,&player);
								    clear_screen();
										if (special == 'l'){
											display_info("Você não tem MP suficiente!");
										    display_stats(&player, &enemy);
												sprite_mc(1,1);                      
												sprite_enemy(&enemy,1,1);
												sprite_mc(1,2);
												sprite_enemy(&enemy,1,2);
												sprite_mc(1,3);
												sprite_enemy(&enemy,1,3);
												display_commands();
													Sleep(500);
													clear_screen();
													continue;
													}
													else if (special == 'a'){
											        player.mp -= 10;
											        if(ataque(30)==1){
											            char acao[38] = {""};
											            strcpy(acao, player.nome);
											            strcat(acao, " Usou ataque pesado!");
												            display_info(acao);
														    display_stats(&player, &enemy);    
														    sprite_mc(2,1);            //Sprite 2 do jogador
														    sprite_enemy(&enemy,1,1);
														    sprite_mc(2,2);
														    sprite_enemy(&enemy,1,2);
														    sprite_mc(2,3);
														    sprite_enemy(&enemy,1,3);
														    display_commands();
															    Sleep(500);
															    clear_screen();
																    enemy.hp -= player.forca * 2;
														            display_info(acao);
																    display_stats(&player, &enemy);
																    sprite_mc(3,1);             //Sprite 3 do jogador
																    sprite_enemy(&enemy,1,1);
																    sprite_mc(3,2);
																    sprite_enemy(&enemy,1,2);
																    sprite_mc(3,3);
																    sprite_enemy(&enemy,1,3);
																    display_commands();
																	    Sleep(500);
																	    clear_screen();
											        				}else{
															            char acao[38] = {""};
															            strcpy(acao, player.nome);
															            strcat(acao, " Usou ataque pesado, mas errou!");
																            display_info(acao);
																		    display_stats(&player, &enemy);    
																		    sprite_mc(2,1);            //Sprite 2 do jogador
																		    sprite_enemy(&enemy,1,1);
																		    sprite_mc(2,2);
																		    sprite_enemy(&enemy,1,2);
																		    sprite_mc(2,3);
																		    sprite_enemy(&enemy,1,3);
																		    display_commands();
																			    Sleep(500);
														    					clear_screen();
																            display_info(acao);
																		    display_stats(&player, &enemy);
																		    sprite_mc(3,1);             //Sprite 3 do jogador
																		    sprite_enemy(&enemy,1,1);
																		    sprite_mc(3,2);
																		    sprite_enemy(&enemy,1,2);
																		    sprite_mc(3,3);
																		    sprite_enemy(&enemy,1,3);
																		    display_commands();
																			    Sleep(500);
																			    clear_screen();
											       							}  
																		}
																	        if (special == 'b'){
																	            player.mp -= 20;
																	        	if(ataque(50)==1){
																		            char acao[38] = {""};
																		            strcpy(acao, player.nome);
																		            strcat(acao, " Usou treme solo!");
																			            display_info(acao);
																					    display_stats(&player, &enemy);    
																					    sprite_mc(2,1);            //Sprite 2 do jogador
																					    sprite_enemy(&enemy,1,1);
																					    sprite_mc(2,2);
																					    sprite_enemy(&enemy,1,2);
																					    sprite_mc(2,3);
																					    sprite_enemy(&enemy,1,3);
																						    display_commands();
																						    Sleep(500);
		    																			clear_screen();
																					    enemy.hp -= player.forca * 3;
																			            display_info(acao);
																					    display_stats(&player, &enemy);
																					    sprite_mc(3,1);             //Sprite 3 do jogador
																					    sprite_enemy(&enemy,1,1);
																					    sprite_mc(3,2);
																					    sprite_enemy(&enemy,1,2);
																					    sprite_mc(3,3);
																					    sprite_enemy(&enemy,1,3);
																					    display_commands();
																						    Sleep(500);
																						    clear_screen();
																				        }else{
																				            char acao[38] = {""};
																					            strcpy(acao, player.nome);
																					            strcat(acao, " Usou treme solo, Mas Errou!");
																						            display_info(acao);
																								    display_stats(&player, &enemy);    
																								    sprite_mc(2,1);            //Sprite 2 do jogador
																								    sprite_enemy(&enemy,1,1);
																								    sprite_mc(2,2);
																								    sprite_enemy(&enemy,1,2);
																								    sprite_mc(2,3);
																								    sprite_enemy(&enemy,1,3);
																								    display_commands();
																									    Sleep(500);
																									    clear_screen();
																						            display_info(acao);
																								    display_stats(&player, &enemy);
																								    sprite_mc(3,1);             //Sprite 3 do jogador
																								    sprite_enemy(&enemy,1,1);
																								    sprite_mc(3,2);
																								    sprite_enemy(&enemy,1,2);
																								    sprite_mc(3,3);
																								    sprite_enemy(&enemy,1,3);
																								    display_commands();
																									    Sleep(500);
																									    clear_screen();
																				        			}  
																				        		}
																						        if (special == 'c'){
																						        player.mp -= 25;
																						        	if(ataque(80)==1){
																							            char acao[38] = {""};
																							            strcpy(acao, player.nome);
																							            strcat(acao, " Usou rompe tormentas!");
																								            display_info(acao);
																										    display_stats(&player, &enemy);    
																										    sprite_mc(2,1);            //Sprite 2 do jogador
																										    sprite_enemy(&enemy,1,1);
																										    sprite_mc(2,2);
																										    sprite_enemy(&enemy,1,2);
																										    sprite_mc(2,3);
																										    sprite_enemy(&enemy,1,3);
																										    display_commands();
																											    Sleep(500);
																											    clear_screen();
																										    enemy.hp -= enemy.hp;
																								            display_info(acao);
																										    display_stats(&player, &enemy);
																										    sprite_mc(3,1);             //Sprite 3 do jogador
																										    sprite_enemy(&enemy,1,1);
																										    sprite_mc(3,2);
																										    sprite_enemy(&enemy,1,2);
																										    sprite_mc(3,3);
																										    sprite_enemy(&enemy,1,3);
																										    display_commands();
																											    Sleep(500);
																									    		clear_screen();
											            
																									        }else{
																									            char acao[38] = {""};
																									            strcpy(acao, player.nome);
																									            strcat(acao, " Usou rompe tormentas, Mas Errou!");
																									            display_info(acao);
																												    display_stats(&player, &enemy);    
																												    sprite_mc(2,1);            //Sprite 2 do jogador
																												    sprite_enemy(&enemy,1,1);
																												    sprite_mc(2,2);
																												    sprite_enemy(&enemy,1,2);
																												    sprite_mc(2,3);
																												    sprite_enemy(&enemy,1,3);
																												    display_commands();
																													    Sleep(500);
																													    clear_screen();
																										            display_info(acao);
																												    display_stats(&player, &enemy);
																												    sprite_mc(3,1);             //Sprite 3 do jogador
																												    sprite_enemy(&enemy,1,1);
																												    sprite_mc(3,2);
																												    sprite_enemy(&enemy,1,2);
																												    sprite_mc(3,3);
																												    sprite_enemy(&enemy,1,3);
																												    display_commands();
																													    Sleep(500);
																													    clear_screen();
																								        			}
																								        		}  
																										        if (special == 'v'){
																										         continue;
																										    }
																										}	
																								        else if (input == '3'){
																								        	if(ataque(0) == 1){
																											defendeu = 1;
																								            clear_screen();
																									            char acao[38] = {""};
																									            strcpy(acao, player.nome);
																									            strcat(acao, " Defendeu!");
																										            display_info(acao);
																												    display_stats(&player, &enemy);    
																												    sprite_mc(2,1);             
																												    sprite_enemy(&enemy,1,1);
																												    sprite_mc(2,2);
																												    sprite_enemy(&enemy,1,2);
																												    sprite_mc(2,3);
																												    sprite_enemy(&enemy,1,3);
																												    display_commands();
																													    Sleep(500);
																													    clear_screen();
																								        				}
																								        			}
																													else if (input == '4'){
																														clear_screen();
																														display_info("");
																													    display_stats(&player, &enemy);
																														    sprite_mc(1,1);
																														    sprite_enemy(&enemy,1,1);
																														    sprite_mc(1,2);
																														    sprite_enemy(&enemy,1,2);
																														    sprite_mc(1,3);
																														    sprite_enemy(&enemy,1,3);
																											        			int potion = display_skills(4,&player);
																																	if (potion == 'm'){
																																		clear_screen();
																																		display_info("Você não tem mais poção!");
																																		    display_stats(&player, &enemy);
																																			sprite_mc(1,1);                     
																																			sprite_enemy(&enemy,1,1);
																																			sprite_mc(1,2);
																																			sprite_enemy(&enemy,1,2);
																																			sprite_mc(1,3);
																																			sprite_enemy(&enemy,1,3);
																																			display_commands();
																																				Sleep(500);
																																				clear_screen();
																																			continue;
																																			}
																																        if ( potion == 'd') {
																																			clear_screen();
																																            player.hp += 50;
																																			clear_screen();
																																				if(player.hp > player.hpmax ){
																																				player.hp = player.hpmax;
																																	        }
																																		        char acao[38] = {""};
																																		        strcpy(acao, player.nome);
																																		        strcat(acao, " Usou poção de vida");
																																				    display_stats(&player, &enemy);
																																					sprite_mc(1,1);                       //Usando Pocao de Vida
																																					sprite_enemy(&enemy,1,1);
																																					sprite_mc(1,2);
																																					sprite_enemy(&enemy,1,2);
																																					sprite_mc(1,3);
																																					sprite_enemy(&enemy,1,3);
																																			    }else if( potion == 'e'){
																																					clear_screen();
																																			        player.mp += 50;
																																						if(player.mp > player.mpmax ){
																																						player.mp = player.mpmax;
																																			            }
																																		            char acao[38] = {""};
																																			            strcpy(acao, player.nome);
																																			            strcat(acao, " Usou poção de mana");
																																						display_info("acao");
																																					        display_stats(&player, &enemy);
																																						    sprite_mc(1,1);                       //Usando Pocao de mana
																																						    sprite_enemy(&enemy,1,1);
																																						    sprite_mc(1,2);
																																						    sprite_enemy(&enemy,1,2);
																																						    sprite_mc(1,3);
																																						    sprite_enemy(&enemy,1,3);
																																			        }else if(potion == 'v'){
																																						clear_screen();
																																			            continue;
																																			    }      
																																			}
																																	        if(enemy.hp > 0){
																																				if(ataque(0)==1){
																																            	clear_screen();
																																		            char acao[38] = {""};
																																		            strcpy(acao, enemy.nome);
																																		            strcat(acao, " atacou!");
																																			            display_info(acao);
																																					    display_stats(&player, &enemy);
																																					    sprite_mc(1,1);                   //Sprite 2 do inimigo
																																					    sprite_enemy(&enemy,2,1);
																																					    sprite_mc(1,2);
																																					    sprite_enemy(&enemy,2,2);
																																					    sprite_mc(1,3);
																																					    sprite_enemy(&enemy,2,3);
																																					    display_commands();
																																						    Sleep(500);
																																						    clear_screen();
																																						if (defendeu == '1'){
																																						player.hp -= (player.forca - 20);
																																						defendeu = 0;	
																																							}else{
																																								player.hp -= 20;
																																					            }
																																					            display_info(acao);
																																							    display_stats(&player, &enemy);
																																							    sprite_mc(1,1);                //Sprite 3 do Inimigo
																																							    sprite_enemy(&enemy,3,1);
																																							    sprite_mc(1,2);
																																							    sprite_enemy(&enemy,3,2);
																																							    sprite_mc(1,3);
																																							    sprite_enemy(&enemy,3,3);
																																							    display_commands();
																																								    Sleep(500);
																																								    clear_screen();
																																					        }else{
																																					            clear_screen();
																																						            char acao[38] = {""};
																																						            strcpy(acao, enemy.nome);
																																						            strcat(acao, " atacou, mas errou!");
																																							            display_info(acao);
																																									    display_stats(&player, &enemy);
																																									    sprite_mc(1,1);                   //Sprite 2 do inimigo
																																									    sprite_enemy(&enemy,2,1);
																																									    sprite_mc(1,2);
																																									    sprite_enemy(&enemy,2,2);
																																									    sprite_mc(1,3);
																																									    sprite_enemy(&enemy,2,3);
																																									    display_commands();
																																										    Sleep(500);
																																										    clear_screen();
																																							            display_info(acao);
																																									    display_stats(&player, &enemy);
																																									    sprite_mc(1,1);                //Sprite 3 do Inimigo
																																									    sprite_enemy(&enemy,3,1);
																																									    sprite_mc(1,2);
																																									    sprite_enemy(&enemy,3,2);
																																									    sprite_mc(1,3);
																																									    sprite_enemy(&enemy,3,3);
																																									    display_commands();
																																										    Sleep(500);
																																										    clear_screen();           
																																					        				}			
																																					    				}
																																					    			}
																																							if(player.hp > 0){
																																								printf("Apos enfrentar seu inimigo, o jovem %s enfrenta dificeis provações, resolvendo questionamento acerca de formulas estranhas\n",player.nome);
																																								printf("Quase como se parecessem coisas de outro mundo\n");
																																									Sleep(8000);
																																									clear_screen();
																																						    	}
limparBufferEntrada();

while (player.hp > 0 && enemy2.hp > 0) {
		if (player.mp < 0){
		player.mp = 0;
        }
		display_info("");
        display_stats(&player, &enemy2);
		sprite_mc(1,1);                       //Sprite 1 do jogador e do inimigo (repouso)
		sprite_enemy(&enemy2,1,1);
		sprite_mc(1,2);
		sprite_enemy(&enemy2,1,2);
		sprite_mc(1,3);
		sprite_enemy(&enemy2,1,3);
		display_commands();
        input = getch();
			if(input == '1'){
        		if(ataque(-enemy2.destreza)==1){
				Sleep(500);
				clear_screen();
			        char acao[38] = {""};
				        strcpy(acao, player.nome);
				        strcat(acao, " atacou!");
				        display_info(acao);
						display_stats(&player, &enemy2);    
						sprite_mc(2,1);            //Sprite 2 do jogador
						sprite_enemy(&enemy2,1,1);
						sprite_mc(2,2);
						sprite_enemy(&enemy2,1,2);
						sprite_mc(2,3);
						sprite_enemy(&enemy2,1,3);
						display_commands();
							Sleep(500);
							clear_screen();
						enemy2.hp -= player.forca;
				        display_info(acao);
						display_stats(&player, &enemy2);
						sprite_mc(3,1);             //Sprite 3 do jogador
						sprite_enemy(&enemy2,1,1);
						sprite_mc(3,2);
						sprite_enemy(&enemy2,1,2);
						sprite_mc(3,3);
						sprite_enemy(&enemy2,1,3);
						display_commands();
							Sleep(500);
							clear_screen();       
				        }else{
						Sleep(500);
						clear_screen();
					        char acao[38] = {""};
					        strcpy(acao, player.nome);
					        strcat(acao, " atacou, Mas errou!");
						        display_info(acao);
								display_stats(&player, &enemy2);    
								sprite_mc(2,1);            //Sprite 2 do jogador
								sprite_enemy(&enemy2,1,1);
								sprite_mc(2,2);
								sprite_enemy(&enemy2,1,2);
								sprite_mc(2,3);
								sprite_enemy(&enemy2,1,3);
								display_commands();
									Sleep(500);
									clear_screen();
					       	 	display_info(acao);
								display_stats(&player, &enemy2);
								sprite_mc(3,1);             //Sprite 3 do jogador
								sprite_enemy(&enemy2,1,1);
								sprite_mc(3,2);
								sprite_enemy(&enemy2,1,2);
								sprite_mc(3,3);
								sprite_enemy(&enemy2,1,3);
								display_commands();
									Sleep(500);
									clear_screen();   
					        	}
					        }
							else if (input == '2'){
						        clear_screen();
							    display_stats(&player, &enemy2);
								sprite_mc(1,1);                       //Tela de Habilidades (repouso)
								sprite_enemy(&enemy2,1,1);
								sprite_mc(1,2);
								sprite_enemy(&enemy2,1,2);
								sprite_mc(1,3);
								sprite_enemy(&enemy2,1,3);
									int special = display_skills(2,&player);
							        clear_screen();
										if (special == 'l'){
											display_info("Você não tem MP suficiente!");
											display_stats(&player, &enemy2);
												sprite_mc(1,1);                      
												sprite_enemy(&enemy2,1,1);
												sprite_mc(1,2);
												sprite_enemy(&enemy2,1,2);
												sprite_mc(1,3);
												sprite_enemy(&enemy2,1,3);
												display_commands();
													Sleep(500);
													clear_screen();
												continue;
												}else if (special == 'a'){
														    player.mp -= 10;
													        	if(ataque(30)==1){
														            char acao[38] = {""};
														            strcpy(acao, player.nome);
														            strcat(acao, " Usou ataque pesado!");
															            display_info(acao);
																	    display_stats(&player, &enemy2);    
																	    sprite_mc(2,1);            //Sprite 2 do jogador
																	    sprite_enemy(&enemy2,1,1);
																	    sprite_mc(2,2);
																	    sprite_enemy(&enemy2,1,2);
																	    sprite_mc(2,3);
																	    sprite_enemy(&enemy2,1,3);
																		    display_commands();
																		    Sleep(500);
																	    clear_screen();
																	    enemy2.hp -= player.forca * 2;
															            display_info(acao);
																	    display_stats(&player, &enemy2);
																	    sprite_mc(3,1);             //Sprite 3 do jogador
																	    sprite_enemy(&enemy2,1,1);
																	    sprite_mc(3,2);
																	    sprite_enemy(&enemy2,1,2);
																	    sprite_mc(3,3);
																	    sprite_enemy(&enemy2,1,3);
																	    display_commands();
																		    Sleep(500);
																		    clear_screen();
															        }else{
															            char acao[38] = {""};
															            strcpy(acao, player.nome);
															            strcat(acao, " Usou ataque pesado, mas errou!");
																            display_info(acao);
																		    display_stats(&player, &enemy2);    
																		    sprite_mc(2,1);            //Sprite 2 do jogador
																		    sprite_enemy(&enemy2,1,1);
																		    sprite_mc(2,2);
																		    sprite_enemy(&enemy2,1,2);
																		    sprite_mc(2,3);
																		    sprite_enemy(&enemy2,1,3);
																			    display_commands();
																			    Sleep(500);
																		    clear_screen();
																            display_info(acao);
																		    display_stats(&player, &enemy2);
																		    sprite_mc(3,1);             //Sprite 3 do jogador
																		    sprite_enemy(&enemy2,1,1);
																		    sprite_mc(3,2);
																		    sprite_enemy(&enemy2,1,2);
																		    sprite_mc(3,3);
																		    sprite_enemy(&enemy2,1,3);
																		    display_commands();
																			    Sleep(500);
																			    clear_screen();
															        		}  
															        }
															        if (special == 'b'){
															            player.mp -= 20;
																	        if(ataque(50)==1){
																	            char acao[38] = {""};
																	            strcpy(acao, player.nome);
																	            strcat(acao, " Usou treme solo!");
																		            display_info(acao);
																				    display_stats(&player, &enemy2);    
																				    sprite_mc(2,1);            //Sprite 2 do jogador
																				    sprite_enemy(&enemy2,1,1);
																				    sprite_mc(2,2);
																				    sprite_enemy(&enemy2,1,2);
																				    sprite_mc(2,3);
																				    sprite_enemy(&enemy2,1,3);
																				    display_commands();
																					    Sleep(500);
																					    clear_screen();
																				    enemy2.hp -= player.forca * 3;
																		            display_info(acao);
																				    display_stats(&player, &enemy2);
																				    sprite_mc(3,1);             //Sprite 3 do jogador
																				    sprite_enemy(&enemy2,1,1);
																				    sprite_mc(3,2);
																				    sprite_enemy(&enemy2,1,2);
																				    sprite_mc(3,3);
																				    sprite_enemy(&enemy2,1,3);
																				    display_commands();
																					    Sleep(500);
																					    clear_screen();
															        				}else{
																			            char acao[38] = {""};
																			            strcpy(acao, player.nome);
																			            strcat(acao, " Usou treme solo, Mas Errou!");
																				            display_info(acao);
																						    display_stats(&player, &enemy2);    
																						    sprite_mc(2,1);            //Sprite 2 do jogador
																						    sprite_enemy(&enemy2,1,1);
																						    sprite_mc(2,2);
																						    sprite_enemy(&enemy2,1,2);
																						    sprite_mc(2,3);
																						    sprite_enemy(&enemy2,1,3);
																							    display_commands();
																							    Sleep(500);
																						    clear_screen();
																				            display_info(acao);
																						    display_stats(&player, &enemy2);
																						    sprite_mc(3,1);             //Sprite 3 do jogador
																						    sprite_enemy(&enemy2,1,1);
																						    sprite_mc(3,2);
																						    sprite_enemy(&enemy2,1,2);
																						    sprite_mc(3,3);
																						    sprite_enemy(&enemy2,1,3);
																						    display_commands();
																							    Sleep(500);
																							    clear_screen();
																			        		}  
																			        	}
																				        if (special == 'c'){
																				        player.mp -= 25;
																				        	if(ataque(80)==1){
																					            char acao[38] = {""};
																					            strcpy(acao, player.nome);
																					            strcat(acao, " Usou rompe tormentas!");
																						            display_info(acao);
																								    display_stats(&player, &enemy2);    
																								    sprite_mc(2,1);            //Sprite 2 do jogador
																								    sprite_enemy(&enemy2,1,1);
																								    sprite_mc(2,2);
																								    sprite_enemy(&enemy2,1,2);
																								    sprite_mc(2,3);
																								    sprite_enemy(&enemy2,1,3);
																								    display_commands();
																									    Sleep(500);
																									    clear_screen();
																								    enemy2.hp -= enemy2.hp;
																						            display_info(acao);
																								    display_stats(&player, &enemy2);
																								    sprite_mc(3,1);             //Sprite 3 do jogador
																								    sprite_enemy(&enemy2,1,1);
																								    sprite_mc(3,2);
																								    sprite_enemy(&enemy2,1,2);
																								    sprite_mc(3,3);
																								    sprite_enemy(&enemy2,1,3);
																								    display_commands();
																									    Sleep(500);
																									    clear_screen();     
																						        }else{
																						            char acao[38] = {""};
																						            strcpy(acao, player.nome);
																						            strcat(acao, " Usou rompe tormentas, Mas Errou!");
																							            display_info(acao);
																									    display_stats(&player, &enemy2);    
																									    sprite_mc(2,1);            //Sprite 2 do jogador
																									    sprite_enemy(&enemy2,1,1);
																									    sprite_mc(2,2);
																									    sprite_enemy(&enemy2,1,2);
																									    sprite_mc(2,3);
																									    sprite_enemy(&enemy2,1,3);
																									    display_commands();
																										    Sleep(500);
																										    clear_screen();
																							            display_info(acao);
																									    display_stats(&player, &enemy2);
																									    sprite_mc(3,1);             //Sprite 3 do jogador
																									    sprite_enemy(&enemy2,1,1);
																									    sprite_mc(3,2);
																									    sprite_enemy(&enemy2,1,2);
																									    sprite_mc(3,3);
																									    sprite_enemy(&enemy2,1,3);
																									    display_commands();
																										    Sleep(500);
																										    clear_screen();
																							        	}
																									}
																						        if (special == 'v'){
																						         continue;
																						        }
																							}
																					        else if (input == '3'){
																						        if(ataque(0) == 1){
																									defendeu = 1;
																						            clear_screen();
																							            char acao[38] = {""};
																							            strcpy(acao, player.nome);
																							            strcat(acao, " Defendeu!");
																								            display_info(acao);
																										    display_stats(&player, &enemy2);    
																										    sprite_mc(2,1);             
																										    sprite_enemy(&enemy2,1,1);
																										    sprite_mc(2,2);
																										    sprite_enemy(&enemy2,1,2);
																										    sprite_mc(2,3);
																										    sprite_enemy(&enemy2,1,3);
																										    display_commands();
																											    Sleep(500);
																											    clear_screen();
																						        			}
																						        		}
																										else if (input == '4'){
																											clear_screen();
																											display_info("");
																										    display_stats(&player, &enemy2);
																										    sprite_mc(1,1);
																										    sprite_enemy(&enemy2,1,1);
																										    sprite_mc(1,2);
																										    sprite_enemy(&enemy2,1,2);
																										    sprite_mc(1,3);
																										    sprite_enemy(&enemy2,1,3);
																										        int potion = display_skills(4,&player);
																													if (potion == 'm'){
																														clear_screen();
																														display_info("Você não tem mais poção!");
																													    display_stats(&player, &enemy);
																															sprite_mc(1,1);                     
																															sprite_enemy(&enemy,1,1);
																															sprite_mc(1,2);
																															sprite_enemy(&enemy,1,2);
																															sprite_mc(1,3);
																															sprite_enemy(&enemy,1,3);
																															display_commands();
																																Sleep(500);
																																clear_screen();
																															continue;
																															}
																													        if ( potion == 'd') {
																																clear_screen();
																													            player.hp += 50;
																																clear_screen();
																																	if(player.hp > player.hpmax ){
																																	player.hp = player.hpmax;
																														            }
																														            char acao[38] = {""};
																														            strcpy(acao, player.nome);
																														            strcat(acao, " Usou poção de vida");
																																        display_stats(&player, &enemy2);
																																	    sprite_mc(1,1);                       //Usando Pocao de Vida
																																	    sprite_enemy(&enemy2,1,1);
																																	    sprite_mc(1,2);
																																	    sprite_enemy(&enemy2,1,2);
																																	    sprite_mc(1,3);
																																	    sprite_enemy(&enemy2,1,3);
																															        }else if( potion == 'e'){
																																		clear_screen();
																															            player.mp += 50;
																																			if(player.mp > player.mpmax ){
																																			player.mp = player.mpmax;
																																            }
																																            char acao[38] = {""};
																																            strcpy(acao, player.nome);
																																            strcat(acao, " Usou poção de mana");
																																			display_info("acao");
																																		        display_stats(&player, &enemy2);
																																			    sprite_mc(1,1);                       //Usando Pocao de mana
																																			    sprite_enemy(&enemy2,1,1);
																																			    sprite_mc(1,2);
																																			    sprite_enemy(&enemy2,1,2);
																																			    sprite_mc(1,3);
																																			    sprite_enemy(&enemy2,1,3);
																																	        }else if(potion == 'v'){
																																				clear_screen();
																																	            continue;
																																	        	}
																																	        }
																																	        if(enemy2.hp > 0){
																																		        if(ataque(0)==1){
																																		            clear_screen();
																																			            char acao[38] = {""};
																																			            strcpy(acao, enemy2.nome);
																																			            strcat(acao, " atacou!");
																																				            display_info(acao);
																																						    display_stats(&player, &enemy2);
																																						    sprite_mc(1,1);                   //Sprite 2 do inimigo
																																						    sprite_enemy(&enemy2,2,1);
																																						    sprite_mc(1,2);
																																						    sprite_enemy(&enemy2,2,2);
																																						    sprite_mc(1,3);
																																						    sprite_enemy(&enemy2,2,3);
																																						    display_commands();
																																							    Sleep(500);
																																							    clear_screen();
																																							if (defendeu == '1'){
																																							player.hp -= (player.forca - 20);
																																							defendeu = 0;	
																																							}else{
																																							player.hp -= 20;
																																				            }
																																					            display_info(acao);
																																							    display_stats(&player, &enemy2);
																																							    sprite_mc(1,1);                //Sprite 3 do Inimigo
																																							    sprite_enemy(&enemy2,3,1);
																																							    sprite_mc(1,2);
																																							    sprite_enemy(&enemy2,3,2);
																																							    sprite_mc(1,3);
																																							    sprite_enemy(&enemy2,3,3);
																																							    display_commands();
																																								    Sleep(500);
																																								    clear_screen();
																																					        }else{
																																					            clear_screen();
																																						            char acao[38] = {""};
																																						            strcpy(acao, enemy2.nome);
																																						            strcat(acao, " atacou, mas errou!");
																																							            display_info(acao);
																																									    display_stats(&player, &enemy2);
																																									    sprite_mc(1,1);                   //Sprite 2 do inimigo
																																									    sprite_enemy(&enemy2,2,1);
																																									    sprite_mc(1,2);
																																									    sprite_enemy(&enemy2,2,2);
																																									    sprite_mc(1,3);
																																									    sprite_enemy(&enemy2,2,3);
																																										    display_commands();
																																										    Sleep(500);
																																									    clear_screen();
																																							            display_info(acao);
																																									    display_stats(&player, &enemy2);
																																									    sprite_mc(1,1);                //Sprite 3 do Inimigo
																																									    sprite_enemy(&enemy2,3,1);
																																									    sprite_mc(1,2);
																																									    sprite_enemy(&enemy2,3,2);
																																									    sprite_mc(1,3);
																																									    sprite_enemy(&enemy2,3,3);
																																									    display_commands();
																																										    Sleep(500);
																																										    clear_screen();           
																																									        }
																																									   	}
																																									}
																																									if(player.hp > 0){
																																									     printf("Derrotando mais um inimigo e enfrentando provações cada vez mais dificeis %s, avança para a ultima etapa\n",player.nome);
																																										 printf("uma sala onde o terrivel filho do mestre Makson, que guarda o Pergaminho de Diplom\n");
																																										 printf("um incrivel artefato que concede ao usuario incriveis poderes e comprova que vencestes a jornada aterrorizante");
																																											 Sleep(8000);
																																											 clear_screen();
																																								     		}
	 
    while (player.hp > 0 && boss.hp > 0) {
        if (player.mp < 0){
		player.mp = 0;
        }
		display_info("");
        display_stats(&player, &boss);
		sprite_mc(1,1);                       //Sprite 1 do jogador e do inimigo (repouso)
		sprite_enemy(&boss,1,1);
		sprite_mc(1,2);
		sprite_enemy(&boss,1,2);
		sprite_mc(1,3);
		sprite_enemy(&boss,1,3);
		display_commands();
        input = getch();
			if(input == '1'){
        		if(ataque(-boss.destreza)==1){
				Sleep(500);
				clear_screen();
			        char acao[38] = {""};
			        strcpy(acao, player.nome);
			        strcat(acao, " atacou!");
				        display_info(acao);
						display_stats(&player, &boss);    
						sprite_mc(2,1);            //Sprite 2 do jogador
						sprite_enemy(&boss,1,1);
						sprite_mc(2,2);
						sprite_enemy(&boss,1,2);
						sprite_mc(2,3);
						sprite_enemy(&boss,1,3);
						display_commands();
							Sleep(500);
							clear_screen();
						boss.hp -= player.forca;
				        display_info(acao);
						display_stats(&player, &boss);
						sprite_mc(3,1);             //Sprite 3 do jogador
						sprite_enemy(&boss,1,1);
						sprite_mc(3,2);
						sprite_enemy(&boss,1,2);
						sprite_mc(3,3);
						sprite_enemy(&boss,1,3);
						display_commands();
							Sleep(500);
							clear_screen();   
				        }else{
						Sleep(500);
						clear_screen();
					        char acao[38] = {""};
					        strcpy(acao, player.nome);
					        strcat(acao, " atacou, Mas errou!");
						        display_info(acao);
								display_stats(&player, &boss);    
								sprite_mc(2,1);            //Sprite 2 do jogador
								sprite_enemy(&boss,1,1);
								sprite_mc(2,2);
								sprite_enemy(&boss,1,2);
								sprite_mc(2,3);
								sprite_enemy(&boss,1,3);
								display_commands();
									Sleep(500);
									clear_screen();
						        display_info(acao);
								display_stats(&player, &boss);
								sprite_mc(3,1);             //Sprite 3 do jogador
								sprite_enemy(&boss,1,1);
								sprite_mc(3,2);
								sprite_enemy(&boss,1,2);
								sprite_mc(3,3);
								sprite_enemy(&boss,1,3);
								display_commands();
									Sleep(500);
									clear_screen();   
						        	}					
						       }
								else if (input == '2'){
						        clear_screen();
							    display_stats(&player, &boss);
								sprite_mc(1,1);                       //Tela de Habilidades (repouso)
								sprite_enemy(&boss,1,1);
								sprite_mc(1,2);
								sprite_enemy(&boss,1,2);
								sprite_mc(1,3);
								sprite_enemy(&boss,1,3);
									int special = display_skills(2,&player);
						        	clear_screen();
										if (special == 'l'){
											display_info("Você não tem MP suficiente!");
										    display_stats(&player, &boss);
											sprite_mc(1,1);                      
											sprite_enemy(&boss,1,1);
											sprite_mc(1,2);
											sprite_enemy(&boss,1,2);
											sprite_mc(1,3);
											sprite_enemy(&boss,1,3);
											display_commands();
												Sleep(500);
												clear_screen();
											continue;
											}
							        		if (special == 'a'){
									        player.mp -= 10;
									        if(ataque(30)==1){
									            char acao[38] = {""};
									            strcpy(acao, player.nome);
									            strcat(acao, " Usou ataque pesado!");
										            display_info(acao);
												    display_stats(&player, &boss);    
												    sprite_mc(2,1);            //Sprite 2 do jogador
												    sprite_enemy(&enemy2,1,1);
												    sprite_mc(2,2);
												    sprite_enemy(&enemy2,1,2);
												    sprite_mc(2,3);
												    sprite_enemy(&enemy2,1,3);
												    display_commands();
													    Sleep(500);
													    clear_screen();
												    boss.hp -= player.forca * 2;
										            display_info(acao);
												    display_stats(&player, &boss);
												    sprite_mc(3,1);             //Sprite 3 do jogador
												    sprite_enemy(&enemy2,1,1);
												    sprite_mc(3,2);
												    sprite_enemy(&enemy2,1,2);
												    sprite_mc(3,3);
												    sprite_enemy(&enemy2,1,3);
												    display_commands();
													    Sleep(500);
													    clear_screen();
										        	}else{
											            char acao[38] = {""};
											            strcpy(acao, player.nome);
											            strcat(acao, " Usou ataque pesado, mas errou!");
												            display_info(acao);
														    display_stats(&player, &boss);    
														    sprite_mc(2,1);            //Sprite 2 do jogador
														    sprite_enemy(&boss,1,1);
														    sprite_mc(2,2);
														    sprite_enemy(&boss,1,2);
														    sprite_mc(2,3);
														    sprite_enemy(&boss,1,3);
														    display_commands();
															    Sleep(500);
															    clear_screen();
												            display_info(acao);
														    display_stats(&player, &boss);
														    sprite_mc(3,1);             //Sprite 3 do jogador
														    sprite_enemy(&boss,1,1);
														    sprite_mc(3,2);
														    sprite_enemy(&boss,1,2);
														    sprite_mc(3,3);
														    sprite_enemy(&boss,1,3);
														    display_commands();
															    Sleep(500);
															    clear_screen();
												        	}  
												        }
												        if (special == 'b'){
												            player.mp -= 20;
													        if(ataque(50)==1){
													            char acao[38] = {""};
													            strcpy(acao, player.nome);
													            strcat(acao, " Usou treme solo!");
														            display_info(acao);
																    display_stats(&player, &boss);    
																    sprite_mc(2,1);            //Sprite 2 do jogador
																    sprite_enemy(&boss,1,1);
																    sprite_mc(2,2);
																    sprite_enemy(&boss,1,2);
																    sprite_mc(2,3);
																    sprite_enemy(&boss,1,3);
																    display_commands();
																	    Sleep(500);
																	    clear_screen();
																    boss.hp -= player.forca * 3;
														            display_info(acao);
																    display_stats(&player, &boss);
																    sprite_mc(3,1);             //Sprite 3 do jogador
																    sprite_enemy(&boss,1,1);
																    sprite_mc(3,2);
																    sprite_enemy(&boss,1,2);
																    sprite_mc(3,3);
																    sprite_enemy(&boss,1,3);
																    display_commands();
																	    Sleep(500);
																	    clear_screen();
													        		}else{
														            char acao[38] = {""};
														            strcpy(acao, player.nome);
														            strcat(acao, " Usou treme solo, Mas Errou!");
															            display_info(acao);
																	    display_stats(&player, &boss);    
																	    sprite_mc(2,1);            //Sprite 2 do jogador
																	    sprite_enemy(&boss,1,1);
																	    sprite_mc(2,2);
																	    sprite_enemy(&boss,1,2);
																	    sprite_mc(2,3);
																	    sprite_enemy(&boss,1,3);
																		    display_commands();
																		    Sleep(500);
																	    clear_screen();
															            display_info(acao);
																	    display_stats(&player, &boss);
																	    sprite_mc(3,1);             //Sprite 3 do jogador
																	    sprite_enemy(&boss,1,1);
																	    sprite_mc(3,2);
																	    sprite_enemy(&boss,1,2);
																	    sprite_mc(3,3);
																	    sprite_enemy(&boss,1,3);
																	    display_commands();
																		    Sleep(500);
																		    clear_screen();
													        			}  
													        		}
															        if (special == 'c'){
															        player.mp -= 25;
															        if(ataque(80)==1){
															            char acao[38] = {""};
															            strcpy(acao, player.nome);
															            strcat(acao, " Usou rompe tormentas!");
																            display_info(acao);
																		    display_stats(&player, &boss);    
																		    sprite_mc(2,1);            //Sprite 2 do jogador
																		    sprite_enemy(&boss,1,1);
																		    sprite_mc(2,2);
																		    sprite_enemy(&boss,1,2);
																		    sprite_mc(2,3);
																		    sprite_enemy(&boss,1,3);
																		    display_commands();
																			    Sleep(500);
																			    clear_screen();
																		    boss.hp -= boss.hp;
																            display_info(acao);
																		    display_stats(&player, &boss);
																		    sprite_mc(3,1);             //Sprite 3 do jogador
																		    sprite_enemy(&boss,1,1);
																		    sprite_mc(3,2);
																		    sprite_enemy(&boss,1,2);
																		    sprite_mc(3,3);
																		    sprite_enemy(&boss,1,3);
																		    display_commands();
																			    Sleep(500);
																			    clear_screen();														            
															        		}else{
																	            char acao[38] = {""};
																	            strcpy(acao, player.nome);
																	            strcat(acao, " Usou rompe tormentas, Mas Errou!");
																		            display_info(acao);
																				    display_stats(&player, &boss);    
																				    sprite_mc(2,1);            //Sprite 2 do jogador
																				    sprite_enemy(&boss,1,1);
																				    sprite_mc(2,2);
																				    sprite_enemy(&boss,1,2);
																				    sprite_mc(2,3);
																				    sprite_enemy(&boss,1,3);
																				    display_commands();
																					    Sleep(500);
																					    clear_screen();
																		            display_info(acao);
																				    display_stats(&player, &boss);
																				    sprite_mc(3,1);             //Sprite 3 do jogador
																				    sprite_enemy(&boss,1,1);
																				    sprite_mc(3,2);
																				    sprite_enemy(&boss,1,2);
																				    sprite_mc(3,3);
																				    sprite_enemy(&boss,1,3);
																				    display_commands();
																					    Sleep(500);
																					    clear_screen();
																		        	}
																		   		}	  
																		        if (special == 'v'){
																		         continue;
																		        }
																		    }	
																	        else if (input == '3'){
																	        if(ataque(0) == 1){
																				defendeu = 1;
																	            clear_screen();
																		            char acao[38] = {""};
																		            strcpy(acao, player.nome);
																		            strcat(acao, " Defendeu!");
																		            display_info(acao);
																				    display_stats(&player, &boss);    
																				    sprite_mc(2,1);             
																				    sprite_enemy(&boss,1,1);
																				    sprite_mc(2,2);
																				    sprite_enemy(&boss,1,2);
																				    sprite_mc(2,3);
																				    sprite_enemy(&boss,1,3);
																				    display_commands();
																					    Sleep(500);
																					    clear_screen();
																		        	}
																		        }
																				else if (input == '4'){
																					clear_screen();
																					display_info("");
																				    display_stats(&player, &boss);
																				    sprite_mc(1,1);
																				    sprite_enemy(&boss,1,1);
																				    sprite_mc(1,2);
																				    sprite_enemy(&boss,1,2);
																				    sprite_mc(1,3);
																				    sprite_enemy(&boss,1,3);
																				        int potion = display_skills(4,&player);
																							if (potion == 'm'){
																								clear_screen();
																								display_info("Você não tem mais poção!");
																							    display_stats(&player, &boss);
																								sprite_mc(1,1);                     
																								sprite_enemy(&boss,1,1);
																								sprite_mc(1,2);
																								sprite_enemy(&boss,1,2);
																								sprite_mc(1,3);
																								sprite_enemy(&boss,1,3);
																								display_commands();
																									Sleep(500);
																									clear_screen();
																								continue;
																								}
																						        if ( potion == 'd') {
																									clear_screen();
																						            player.hp += 50;
																									clear_screen();
																									if(player.hp > player.hpmax ){
																									player.hp = player.hpmax;
																						            }
																						            char acao[38] = {""};
																						            strcpy(acao, player.nome);
																						            strcat(acao, " Usou poção de vida");
																								        display_stats(&player, &boss);
																									    sprite_mc(1,1);                       //Usando Pocao de Vida
																									    sprite_enemy(&boss,1,1);
																									    sprite_mc(1,2);
																									    sprite_enemy(&boss,1,2);
																									    sprite_mc(1,3);
																									    sprite_enemy(&boss,1,3);
																							        }else if( potion == 'e'){
																										clear_screen();
																							            player.mp += 50;
																											if(player.mp > player.mpmax ){
																											player.mp = player.mpmax;
																							            	}
																								            char acao[38] = {""};
																								            strcpy(acao, player.nome);
																								            strcat(acao, " Usou poção de mana");
																											display_info("acao");
																										        display_stats(&player, &boss);
																											    sprite_mc(1,1);                       //Usando Pocao de mana
																											    sprite_enemy(&boss,1,1);
																											    sprite_mc(1,2);
																											    sprite_enemy(&boss,1,2);
																											    sprite_mc(1,3);
																											    sprite_enemy(&boss,1,3);
																									        }else if(potion == 'v'){
																												clear_screen();
																									        continue;
																				        					}	        
																				        				}
			        																					if(boss.hp > 0){
			
																									        if(ataque(0)==1){
																									            clear_screen();
																										            char acao[38] = {""};
																										            strcpy(acao, boss.nome);
																										            strcat(acao, " atacou com sua derivação infernal!");
																											            display_info(acao);
																													    display_stats(&player, &boss);
																													    sprite_mc(1,1);                   //Sprite 2 do inimigo
																													    sprite_enemy(&boss,2,1);
																													    sprite_mc(1,2);
																													    sprite_enemy(&boss,2,2);
																													    sprite_mc(1,3);
																													    sprite_enemy(&boss,2,3);
																													    display_commands();
																														    Sleep(500);
																														    clear_screen();
																														if (defendeu == '1'){
																														player.hp -= (player.forca - 20);
																														defendeu = 0;	
																														}else{
																															player.hp -= 20;
																												            }
																													            display_info(acao);
																															    display_stats(&player, &boss);
																															    sprite_mc(1,1);                //Sprite 3 do Inimigo
																															    sprite_enemy(&boss,3,1);
																															    sprite_mc(1,2);
																															    sprite_enemy(&boss,3,2);
																															    sprite_mc(1,3);
																															    sprite_enemy(&boss,3,3);
																															    display_commands();
																																    Sleep(500);
																																    clear_screen();
																												        		}else{
																														            clear_screen();
																															            char acao[38] = {""};
																															            strcpy(acao, boss.nome);
																															            strcat(acao, " atacou com sua derivação infernal, mas errou!");
																																            display_info(acao);
																																		    display_stats(&player, &boss);
																																		    sprite_mc(1,1);                   //Sprite 2 do inimigo
																																		    sprite_enemy(&boss,2,1);
																																		    sprite_mc(1,2);
																																		    sprite_enemy(&boss,2,2);
																																		    sprite_mc(1,3);
																																		    sprite_enemy(&boss,2,3);
																																		    display_commands();
																																			    Sleep(500);
																																			    clear_screen();
																																            display_info(acao);
																																		    display_stats(&player, &boss);
																																		    sprite_mc(1,1);                //Sprite 3 do Inimigo
																																		    sprite_enemy(&boss,3,1);
																																		    sprite_mc(1,2);
																																		    sprite_enemy(&boss,3,2);
																																		    sprite_mc(1,3);
																																		    sprite_enemy(&boss,3,3);
																																		    display_commands();
																																			    Sleep(500);
																																			    clear_screen();           
																																        	}			
																																    	}
																																    }
																																	if(player.hp > 0){
																																		printf("Depois de uma longa jornada você conseguiu, derrotou o cruel Filho do Mestre\n");
																																		printf("E com o pergaminho de Diplom, você está extremamente poderoso, sendo capaz de reinar toda a lucaf\n");
																																		printf("e agora, quais aventuras o poderoso herói %s irá desbravar?",player.nome);
																																			Sleep(8000);
																																			clear_screen();

	printf("   ####     ##     ##   ##  #######\n");
	Sleep(500);
	printf("  ##  ##   ####    ### ###   ##   #\n");
    Sleep(500);
    printf(" ##       ##  ##   #######   ## #\n");
	Sleep(500);
	printf(" ##       ##  ##   #######   ####\n");
	Sleep(500);
	printf(" ##  ###  ######   ## # ##   ## #\n");
	Sleep(500);
	printf("  ##  ##  ##  ##   ##   ##   ##   #\n");
	Sleep(500);
	printf("   #####  ##  ##   ##   ##  #######\n");
	Sleep(500);
	printf("\n");
	Sleep(500);
	printf("       #####   ##   ##  #######  ######\n");
	Sleep(500);
	printf("      ##   ##  ##   ##   ##   #   ##  ##\n");
	Sleep(500);
	printf("      ##   ##   ## ##    ## #     ##  ##\n");
	Sleep(500);
	printf("      ##   ##   ## ##    ####     #####\n");
	Sleep(500);
	printf("      ##   ##    ###     ## #     ## ##\n");
	Sleep(500);
	printf("      ##   ##    ###     ##   #   ##  ##\n");
	Sleep(500);
	printf("       #####      #     #######  #### ##\n\n");
	Sleep(500);
	printf("Você finalizou o jogo!\n");
    printf("Obrigado por jogar."); 
	printf("\nUma produção do grupo Metendo®."); 
    }else{
	printf("Durante a jornada sombria infelizmente o heroi sucumbiu aos horrores da cruzada, infelizmente ele não\n");
	printf("Realizará suas ambições\n");
	Sleep(8000);
	clear_screen();
	printf("   ####     ##     ##   ##  #######\n");
	Sleep(500);
	printf("  ##  ##   ####    ### ###   ##   #\n");
    Sleep(500);
    printf(" ##       ##  ##   #######   ## #\n");
	Sleep(500);
	printf(" ##       ##  ##   #######   ####\n");
	Sleep(500);
	printf(" ##  ###  ######   ## # ##   ## #\n");
	Sleep(500);
	printf("  ##  ##  ##  ##   ##   ##   ##   #\n");
	Sleep(500);
	printf("   #####  ##  ##   ##   ##  #######\n");
	Sleep(500);
	printf("\n");
	Sleep(500);
	printf("       #####   ##   ##  #######  ######\n");
	Sleep(500);
	printf("      ##   ##  ##   ##   ##   #   ##  ##\n");
	Sleep(500);
	printf("      ##   ##   ## ##    ## #     ##  ##\n");
	Sleep(500);
	printf("      ##   ##   ## ##    ####     #####\n");
	Sleep(500);
	printf("      ##   ##    ###     ## #     ## ##\n");
	Sleep(500);
	printf("      ##   ##    ###     ##   #   ##  ##\n");
	Sleep(500);
	printf("       #####      #     #######  #### ##\n\n");
	Sleep(500);
	printf("Você Morreu.");
	exit(1);
	}
}
