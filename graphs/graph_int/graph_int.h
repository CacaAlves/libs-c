#include "list_void.h"
#include "list_int.h"
typedef struct GraphInt
{
    ListInt *vertexList;
    ListVoid *edgeList;
}GraphInt;

typedef struct EdgeInt {
    int *startVertex;
    int *endVertex;
    int weight;
}EdgeInt;
