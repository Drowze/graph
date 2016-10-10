#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NUMBER_OF_CITIES 25 // e.g. 25 cities implies 25^2 routes

/* Matrix's data. (there ain't no table headers; so I figured it would be
   better to include all the route's info in a struct) */
typedef struct {
  char origin[30];
  char destiny[30];
  int distance;
}s_route;

char **default_cities() {
  static char *cities[] = { // 42 cities. Coincidence?
    "Albany",
    "Albuquerque",
    "Aspen",
    "Atlanta",
    "Boise",
    "Boston",
    "Chicago",
    "Colorado Springs",
    "Dallas",
    "Denver",
    "Detroit",
    "Fort Lauderdale",
    "Grand Canyon",
    "Hounston",
    "Indianopolis",
    "Kansas City",
    "Lake Tahoe",
    "Las Vegas",
    "Little Rock",
    "Los Angeles",
    "Memphis",
    "Miami",
    "Milwaukee",
    "Minneapolis",
    "Nashville",
    // "Nova Orleans",
    // "Nova York",
    // "Omaha",
    // "Orlando",
    // "Palm Springs",
    // "Phoenix",
    // "Portland",
    // "Richmond",
    // "Salt Lake City",
    // "San Antonio",
    // "San Diego",
    // "San Francisco",
    // "Seatle",
    // "St Louis",
    // "Vail",
    // "Washington",
    // "Yellowstone",
  };
  // cities = {"teste1", "teste2", "teste3", "teste4", "teste5"};
  return cities;
}

// int **initialize_matrix(char *cities[]) {
//   // doesn't work as intended
//   /* expected behavior: initialize a dynamic int matrix, 
//      of the size equal to the number of words in "cities" 
//      afterwards, zerofy everything. */

//   int i;
//   while(cities[i]) i++;
//   int **graph_map = (int**)malloc(i*sizeof(int));

//   return graph_map; 
// }

void initialize_matrix(int graph_map[NUMBER_OF_CITIES][NUMBER_OF_CITIES]) {
  int i, j;
  for(i = 0; i < NUMBER_OF_CITIES; i++)
    for(j = 0; j < NUMBER_OF_CITIES; j++)
      graph_map[i][j] = 0;
}



/* ---- */
void insert_city(char city[], char *cities[]) {
  // insert a new city to the array of words "cities"
}

void edit_route_by_id(int graph_map[][NUMBER_OF_CITIES], int id, int value) {
  int i = id/NUMBER_OF_CITIES;
  int j = id%NUMBER_OF_CITIES;

  graph_map[i][j] = value;
  graph_map[j][i] = value;
}

int edit_route_by_cities(int graph_map[][NUMBER_OF_CITIES], s_route route){
  int i = 0, j = 0;
  while((strcmp(default_cities()[i], route.origin) != 0) && (i<NUMBER_OF_CITIES))
    i++;
  
  if(i>=NUMBER_OF_CITIES)
    return -1; // city does not exist
  i = i * NUMBER_OF_CITIES;

  while((strcmp(default_cities()[j], route.destiny) != 0) && (j<NUMBER_OF_CITIES))
    j++;

  if(j>=NUMBER_OF_CITIES)
    return -1; // city does not exist

  graph_map[i][j] = route.distance;
  graph_map[j][i] = route.distance;
  return 0;
}

void display_graph_map(int graph_map[][NUMBER_OF_CITIES]) {
  int i,j; 
  for(i=0;i<NUMBER_OF_CITIES;i++) {
    for(j=0;j<NUMBER_OF_CITIES;j++) 
      printf("%d ",graph_map[i][j]);
    printf("\n");
  }
}
/* ---- */

void display_routes_id(char *cities[], int graph_map[][NUMBER_OF_CITIES]){
  int i, j, id, row;
  for(i=0; cities[i]; i++)
    for(j=0; cities[j]; j++) {
      id = NUMBER_OF_CITIES * i + j;
      printf("ID: %d | %s -> %s (%d KMs)\n", id, cities[i], cities[j], graph_map[i][j]);
    }
}

int main(int argc, char *argv[]) {
  int i = 0, j = 0;
  int op, id, value;

  char **all_cities = default_cities();
  char city1[30], city2[30];

  s_route route;
  
  int graph_map[NUMBER_OF_CITIES][NUMBER_OF_CITIES];
  initialize_matrix(graph_map);

  do{
    puts("1- Prosseguir");
    puts("2- Verificar ID das rotas");
    puts("3- Editar rota pelo seu ID");
    puts("4- Editar rota pelas suas cidades");
    puts("5- Imprimir o mapa do grafo");
    puts("\n0- Sair");
    scanf("%d", &op);

    switch(op){
      case 0:
        break;

      case 1: 
        break;

      case 2:
        display_routes_id(all_cities, graph_map);
        break;

      case 3:
        printf("Digite o ID e em seguida o valor");
        scanf("%d%d", &id, &value);
        edit_route_by_id(graph_map, id, value);
        break;

      case 4:
        printf("Digite a cidade de partida, a cidade destino e o valor");
        scanf("%s%s%d", route.origin, route.destiny, &route.distance);
        edit_route_by_cities(graph_map, route);
        break;


      case 5:
        display_graph_map(graph_map);
        break;
      default:
        printf("Opcao invalida! TENTE NOVAMENTE!\n\n\n");
    }
  }while(op != 0);
}