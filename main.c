#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

int raiseToPower(int num, int pow);

int *valueToBinary(int i, int rank);

int *elemsForN(int size);

int *binaryElements(int *arr, int size, int count);

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t);

int *toANF(const int *func, int size);

int HammingWeight(const int *function, int size);

int funcIsBalanced(int weight, int pow);

int algebraicDeg(const int *func, int size, int count);

int HammingDistance(const int *func1, const int *func2, int size);

int funcsIsEqual(const int *func1, const int *func2, int size);

int NLinearity(int *func, int size, int count);

int *toPolarTable(const int *function, int size);

int myModulus(int number, int mod);

int *HadamardCoefficients(const int *func, int size, int count);

int HadamardMax(const int *arr, int size);

int HadamardNLinearity(int max, int count);

int *autoCorrelation(int *func, int size, int count);

int autoCorrelationMax(const int *arr, int size);

int expansionCriterion(const int *func, int size, int k);

int *WHT1PlusSet(const int *func, int size, int newSize, int max);

int *WHT1MinusSet(const int *func, int size, int newSize, int max);

int *WHT2PlusSet(const int *func, int size, int newSize, int max);

int *WHT2MinusSet(const int *func, int size, int newSize, int max);

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]);

int *linearFunctions(int size, int count, int t);

int *arrayAdd(const int *arr1, int size1, const int *arr2, int size2);

int *improvementSet(const int func[], const int *linearFunctions, int size, int linearMassSize, int WHTPlusSize);

int *HillClimbing(const int f[], const int *improvementSet, int size, int count);

int *roundableHillClimbing(const int f[], int size, int count);

int *SBoxToBooleanFunc(int *sbox, int size, int count);

int *booleanFunctionsToSBox(const int *arr, int size, int count);

int *propertiesOfBooleanFunc(int *arr, int size, int count);

int *linearCombinations(const int *arr, int size, int count);

int *propertiesOfLinearCombinations(const int *arr, int size, int count);

int *SBoxGenerating(int n, int m);

int *propertiesOfSBox(int *sbox, int size, int count);

int costFunction(int *sbox, int size, int count);

int NLOfSBox(const int *sbox, int size, int count);

int ACOfSBox(int *sbox, int size, int count);

int *simulatedAnnealing(const int *sbox, int size, int count);

int testNL(int *sbox, int size, int count);

int NLOfLinearCombinations(const int *arr, int size, int count);

int deltaUniformity(const int *arr, int size, int count);

int differenceTableMax(const int *sbox, int size);

int *binaryElementsApprox(int *arr, int size, int count);

int *SBoxApprox(int *sbox, int size, int count);

int approxTableMax(int *sbox, int size, int count);

int LATMax(int *sbox, int size, int count);

int cyclicStructure(const int *sbox, int size);

int fixedPoints(const int *sbox, int size);

int minDegCalculation(const int *arr, int size, int count);

int minDegree(int *sbox, int size, int count);

void buildOneRow(int *arr, int *monomials);

int numOfCombinations(int n, int d);

int rankCalculation(int rows, int cols, int a[rows][cols]);

int algebraicImmunity(int *sbox, int size, int count);

int main(int args, char **argv) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int n = 8;
    int size = raiseToPower(2, n);
    //int *binElems = elemsForN(size);
    //int f[] = {0, 0, 1, 0, 0, 1, 1, 0};

    /*int *ar = binaryElements(binElems, size, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar[i*size+j]);
        }
        printf("\n");
    }/*
    /*int *ar3 = calloc(size, sizeof(int));
    int modulus = 0;
    for (int t = 0, k = size - 1; t < size; ++t, k--) {
        int *ar2 = massToBooleanFunc(binElems, ar, size, n, t);
        for (int i = 0; i < size; ++i) {
            //printf("%d ", ar2[i]);
            if (f[i] != 0) {
                //printf("%d ", ar2[i]);
                modulus = modulus ^ ar2[i];
            }
        }
        //printf("modulus = %d ", modulus);
        ar3[k] = modulus;
        modulus = 0;
    }
    printf("\n");
    printf("TRUTH TABLE FOR FUNCTION\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", ar3[i]);
    }
    printf("\n");
    printf("\n");
    printf("ANF REPRESENTATION\n");
    int *ar4 = toANF(ar3, size);
    for (int i = 0; i < size; ++i) {
        printf("%d ", ar4[i]);
    }
    printf("\n");
    printf("\n");
    int weight;
    weight = HammingWeight(ar3, size);
    printf("HAMMING WEIGHT = %d ", weight);
    printf("\n");
    int flag = funcIsBalanced(weight, n);
    int dec = algebraicDeg(f, size, n);
    printf("\n\nALGEBRAIC DEGREE = %d ", dec);
    printf("\n");
    int fun11[] = {1, 1, 1, 1};
    int nel = NLinearity(fun11, 4, 2);
    printf("\nNON LINEARITY (DISTANCE) = %d", nel);
    printf("\n");
    printf("\nPOLAR TABLE");
    printf("\n");
    int *polFunc = toPolarTable(fun11, 4);
    for (int i = 0; i < 4; ++i) {
        printf("%d ", polFunc[i]);
    }
    int *ar5 = HadamardCoefficients(fun11, 4, 2);
    int max = HadamardMax(ar5, 4);
    int nl = HadamardNLinearity(max, 2);
    printf("\nHADAMARD NON LINEARITY = %d", nl);
    printf("\n");
    int fun22[] = {1, 0, 1, 1};
    int *ar6 = autoCorrelation(fun22, 4, 2);
    printf("\nAUTO CORRELATING FUNCTION");
    printf("\n");
    for (int i = 3; i >= 0; i--) {
        printf("%d ", ar6[i]);
    }
    printf("\n");
    int AC = autoCorrelationMax(ar6, 4);
    printf("\nAUTO CORRELATION = %d", AC);
    printf("\n");
    int ec = expansionCriterion(fun22, 4, 1);
    printf("\n");
    printf("\nW = %d", ec);
    printf("\n");
    n = 8;
    size = raiseToPower(2, n);
    int fx[size];
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        fx[i] = rand() % 2;
    }
    printf("\nMY FUNCTION 2^8");
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("%d, ", fx[i]);
    }
    printf("\n");*/

    //int fx[] = {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};
    //int fx[] = {1,0,1,1};
    //int fx[] = {1,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0};
    /*int fx[] = {0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0,
                1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1,
                0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1,
                0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
                0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0,
                1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1,
                1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0};*/
    /*printf("\nTRUTH TABLE");
    printf("\n");
    //size = 256;
    //size = 16;
    //n = 4;
    //size = 4;
    //n = 2;
    //n = 8;
    for (int i = 0; i < size; ++i) {
        printf("%d ", fx[i]);
    }
    int *fxarr = HadamardCoefficients(fx, size, n);
    printf("\nHADAMARD COEFFICIENTS");
    printf("\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", fxarr[i]);
    }
    int max1 = HadamardMax(fxarr, size);
    //printf("\n max = %d", max1);
    int nl2 = HadamardNLinearity(max1, n);
    printf("\n");
    printf("\nHADAMARD NON LINEARITY = %d", nl2);
    printf("\n");
    int sizeWHT1P = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == max1) {
            sizeWHT1P++;
        }
    }
    printf("\nW1 PLUS");
    printf("\n");
    int *WHT1Plus = WHT1PlusSet(fxarr, size, sizeWHT1P, max1);
    if (WHT1Plus) {
        for (int i = 0; i < sizeWHT1P; ++i) {
            printf("%d ", WHT1Plus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");
    int sizeWHT1M = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == -max1) {
            sizeWHT1M++;
        }
    }
    printf("\nW1 MINUS");
    printf("\n");
    int *WHT1Minus = WHT1MinusSet(fxarr, size, sizeWHT1M, max1);
    if (WHT1Minus) {
        for (int i = 0; i < sizeWHT1M; ++i) {
            printf("%d ", WHT1Minus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");
    int sizeWHT2P = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == (max1 - 2)) {
            sizeWHT2P++;
        }
    }
    printf("\nW2 PLUS");
    printf("\n");
    int *WHT2Plus = WHT2PlusSet(fxarr, size, sizeWHT2P, max1);
    if (WHT2Plus) {
        for (int i = 0; i < sizeWHT2P; ++i) {
            printf("%d ", WHT2Plus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");
    int sizeWHT2M = 0;
    for (int i = 0; i < size; ++i) {
        if (fxarr[i] == (max1 - 2)) {
            sizeWHT2M++;
        }
    }
    printf("\nW2 MINUS");
    printf("\n");
    int *WHT2Minus = WHT2MinusSet(fxarr, size, sizeWHT2M, max1);
    if (WHT2Minus) {
        for (int i = 0; i < sizeWHT2M; ++i) {
            printf("%d ", WHT2Minus[i]);
        }
    } else {
        printf("NULL");
    }
    printf("\n");
    // Îòðèìàííÿ îá'ºäíàííÿ WHT1P òà WHT2P
    if (!WHT1Plus && !WHT2Plus) {
        printf("SET WHT PLUS IS NULL");
    } else {
        int c1[(sizeWHT1P + sizeWHT2P)];
        //printf("%d ", (sizeWHT1P + sizeWHT1P));
        int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
        printf("\nSET WHT PLUS");
        printf("\n");
        for (int i = 0; i < m1; ++i) {
            printf("%d ", c1[i]);
        }
    }
    printf("\n");
    // Îòðèìàííÿ îá'ºäíàííÿ WHT1M òà WHT2M
    if (!WHT1Minus && !WHT2Minus) {
        printf("\nSET WHT MINUS IS NULL");
    } else {
        int c2[(sizeWHT1M + sizeWHT2M)];
        //printf("%d ", (sizeWHT1P + sizeWHT1P));
        int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);
        printf("\nSET WHT MINUS");
        printf("\n");
        for (int i = 0; i < m2; ++i) {
            printf("%d ", c2[i]);
        }
    }
    printf("\n");
    int c1[(sizeWHT1P + sizeWHT2P)];
    int c2[(sizeWHT1M + sizeWHT2M)];
    int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
    int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);
    int linearMassSize = m1 + m2;
    int *c = arrayAdd(c1, m1, c2, m2);
    //printf("Linear mass size %d ", linearMassSize);
    printf("\nOMEGA LINEAR FUNCTIONS TO FIND");
    printf("\n");
    for (int i = 0; i < linearMassSize; ++i) {
        printf("%d ", c[i]);
    }
    printf("\n");
    int *linearFunctionsMass = calloc(linearMassSize * 16, sizeof(int));
    for (int i = 0; i < linearMassSize; ++i) {
        int t = c[i];
        int *arr = linearFunctions(size, n, t);
        for (int j = 0; j < size; ++j) {
            //printf("%d ", arr[j]);
            linearFunctionsMass[i * size + j] = arr[j];
            //printf("%d ", linearFunctionsMass[j]);
        }
    }
    printf("\nLINEAR FUNCTIONS");
    printf("\n");
    for (int i = 0; i < linearMassSize; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", linearFunctionsMass[i * size + j]);
        }
        printf("\n");
    }
    printf("\nIMPROVEMENT SET:");
    int *ar8 = improvementSet(fx, linearFunctionsMass, size, linearMassSize, m1);
    printf("\n");
    for (int j = 0; j < size; ++j) {
        printf("%d ", ar8[j]);
    }
    printf("\n");*/


    //HillClimbing(fx, ar8, size, n);

    //n = 4;
    //size = raiseToPower(2,n);

    //int fx2[] = {0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1};

    //int fx2[] = {1,0,1,1};

    /*n = 8;
    size = raiseToPower(2,n);
    int fx2[] = {1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1,
                     0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1,
                     0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0,
                     0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1,
                     1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1,
                     1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,};*/

    /*srand ( time(NULL) );
    for (int i = 0; i < size; ++i){
        fx2[i] = rand() % 2;
    }
    printf("\nMY FUNCTION 2^8");
    printf("\n");
    for (int i = 0; i < size; ++i){
        printf("%d, ", fx2[i]);
    }
    printf("\n");*/

    //int *ar9 = roundableHillClimbing(fx, size, n);

    /*printf("\n");
    int newNonLin = ar9[0];
    printf("\nNEW NON LINEARITY AFTER HILL CLIMBING = ");
    printf("%d ", newNonLin);
    printf("\n");*/

    /*if (ar9 != NULL) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar9[j]);
        }
    } else {
        printf("\nIMPROVEMENT SET:");
    }*/

    /*n = 5;
    size = raiseToPower(2, n);
    int sbox[] = {4, 22, 16, 15, 21, 11, 8, 9, 25, 19, 20, 13, 23, 29, 31, 7, 6, 2, 10, 3, 1, 17, 30, 12, 24, 26, 5, 0,
                  14, 18, 28, 27};
    int *ar7 = SBoxToBooleanFunc(sbox, size, n);*/

    //int *ar8 = propertiesOfBooleanFunc(ar7,size,n);

    /*int *sboxRev = booleanFunctionsToSBox(ar7,size,n);
    printf("\nS-BOX TO DECIMAL FROM BINARY\n");
    for (int i = 0; i < size; ++i){
        printf("%d ", sboxRev[i]);
    }
    printf("\n");
    int sbox2[] = {4, 4, 3, 5, 2, 0, 7, 6};
    int *ar8 = SBoxToBooleanFunc(sbox2, size, n);
    int *sboxRev2 = booleanFunctionsToSBox(ar8,size,n);
    printf("\nS-BOX TO DECIMAL FROM BINARY\n");
    for (int i = 0; i < size; ++i){
        printf("%d ", sboxRev2[i]);
    }
    printf("\n");*/

    /*int *ar10 = linearCombinations(ar7, size, n);
    free(ar7);
    printf("\nLINEAR COMBINATION OF BOOLEAN FUNCTIONS\n");
    for (int i = 0; i < size - 1; ++i) {
        printf("Combination %d = ", i + 1);
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar10[i * size + j]);
        }
        printf("\n");
    }
    int *ar11 = propertiesOfLinearCombinations(ar10, size, n);
    printf("\nNON LINEARITY OF S-BOX IS\n");
    printf("%d ", ar11[0]);
    printf("\n");
    printf("\nAUTO CORRELATION OF S-BOX IS\n");
    printf("%d ", ar11[1]);
    printf("\n");
    printf("\nDEC OF S-BOX IS\n");
    printf("%d ", ar11[2]);
    printf("\n");
    if (ar11[3] == 1) {
        printf("\nS-BOX IS BALANCED\n");
    } else {
        printf("\nS-BOX IS NOT BALANCED\n");
    }
    printf("\n");
    free(ar10);
    free(ar11);*/

    //clock_t tic = clock();
    //int *ar12 = SBoxGenerating(3, 3);

    /*int ar12[] = {3, 106, 87, 164, 169, 243, 112, 241, 109, 0, 128, 135, 90, 16, 129, 44, 28, 34, 157, 103, 35, 113, 143, 67, 172, 33, 210, 104, 24, 222, 152, 65, 23, 105, 51, 195, 204, 160, 74, 224, 179, 239, 218, 215, 197, 85, 56, 41, 27, 29, 198, 99, 186, 141, 155, 47, 140, 124, 170, 13, 206, 6, 177, 173, 146, 154, 214, 184, 187, 192, 227, 50, 255, 194, 233, 45, 188, 232, 9, 95, 11, 249, 223, 54, 14, 156, 237, 61, 55, 202, 166, 117, 70, 163, 121, 134, 15, 231, 151, 165, 250, 81, 211, 216, 228, 48, 196, 238, 84, 150, 46, 226, 101, 144, 108, 58, 64, 251, 37, 149, 183, 40, 252, 73, 102, 174, 52, 8, 208, 77, 212, 167, 242, 10, 229, 92, 100, 230, 98, 12, 136, 1, 59, 225, 161, 116, 69, 178, 219, 107, 153, 86, 71, 142, 115, 246, 125, 213, 190, 57, 7, 66, 133, 32, 118, 94, 162, 122, 30, 88, 76, 148, 20, 247, 39, 205, 203, 79, 145, 130, 83, 217, 31, 193, 221, 180, 2, 138, 191, 89, 137, 175, 158, 60, 17, 139, 201, 234, 240, 176, 4, 126, 49, 5, 235, 38, 110, 80, 119, 68, 120, 199, 131, 236, 220, 159, 253, 254, 53, 26, 93, 97, 245, 244, 75, 18, 209, 82, 207, 248, 63, 147, 185, 171, 132, 78, 43, 189, 200, 91, 22, 96, 181, 21, 36, 111, 72, 114, 19, 123, 25, 168, 42, 62, 127, 182};

    int res = deltaUniformity(ar12,256,8);

    printf("DU = %d ", res);

    int mdt = max_difference_table(ar12);

    printf("MDT = %d ", mdt);*/
    n = 8;
    size = raiseToPower(2, n);

    int ar[] = {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};

    //int ar2[] = {3, 106, 87, 164, 169, 243, 112, 241, 109, 0, 128, 135, 90, 16, 129, 44, 28, 34, 157, 103, 35, 113, 143, 67, 172, 33, 210, 104, 24, 222, 152, 65, 23, 105, 51, 195, 204, 160, 74, 224, 179, 239, 218, 215, 197, 85, 56, 41, 27, 29, 198, 99, 186, 141, 155, 47, 140, 124, 170, 13, 206, 6, 177, 173, 146, 154, 214, 184, 187, 192, 227, 50, 255, 194, 233, 45, 188, 232, 9, 95, 11, 249, 223, 54, 14, 156, 237, 61, 55, 202, 166, 117, 70, 163, 121, 134, 15, 231, 151, 165, 250, 81, 211, 216, 228, 48, 196, 238, 84, 150, 46, 226, 101, 144, 108, 58, 64, 251, 37, 149, 183, 40, 252, 73, 102, 174, 52, 8, 208, 77, 212, 167, 242, 10, 229, 92, 100, 230, 98, 12, 136, 1, 59, 225, 161, 116, 69, 178, 219, 107, 153, 86, 71, 142, 115, 246, 125, 213, 190, 57, 7, 66, 133, 32, 118, 94, 162, 122, 30, 88, 76, 148, 20, 247, 39, 205, 203, 79, 145, 130, 83, 217, 31, 193, 221, 180, 2, 138, 191, 89, 137, 175, 158, 60, 17, 139, 201, 234, 240, 176, 4, 126, 49, 5, 235, 38, 110, 80, 119, 68, 120, 199, 131, 236, 220, 159, 253, 254, 53, 26, 93, 97, 245, 244, 75, 18, 209, 82, 207, 248, 63, 147, 185, 171, 132, 78, 43, 189, 200, 91, 22, 96, 181, 21, 36, 111, 72, 114, 19, 123, 25, 168, 42, 62, 127, 182};

    int ar2[] = {155, 2, 239, 60, 65, 139, 8, 25, 5, 152, 24, 31, 54, 168, 137, 196, 180, 186, 53, 255, 187, 9, 242,
                 219, 68, 185, 106, 0, 176, 118, 48, 217, 175, 11, 203, 91, 100, 56, 226, 120, 75, 135, 114, 111, 93,
                 237, 208, 193, 179, 181, 94, 251, 82, 37, 51, 199, 36, 20, 66, 165, 102, 158, 73, 69, 42, 50, 110, 80,
                 83, 88, 123, 202, 151, 90, 129, 197, 84, 128, 161, 247, 163, 145, 119, 206, 166, 52, 133, 213, 207, 98,
                 62, 13, 222, 59, 17, 30, 167, 127, 47, 61, 146, 233, 107, 112, 124, 200, 92, 134, 236, 46, 198, 122,
                 253, 40, 4, 210, 216, 147, 189, 45, 79, 192, 148, 225, 254, 70, 204, 160, 104, 229, 108, 63, 138, 162,
                 125, 244, 252, 126, 250, 164, 32, 153, 211, 121, 57, 12, 221, 74, 115, 3, 49, 238, 223, 38, 39, 142,
                 55, 109, 86, 209, 159, 218, 29, 184, 14, 246, 58, 18, 182, 240, 228, 44, 172, 143, 191, 101, 99, 231,
                 41, 26, 235, 113, 183, 89, 117, 76, 154, 34, 87, 136, 33, 71, 1, 212, 169, 35, 97, 130, 22, 72, 156,
                 241, 201, 157, 131, 190, 6, 232, 15, 220, 16, 95, 27, 132, 116, 21, 149, 150, 205, 178, 245, 249, 141,
                 140, 227, 170, 105, 234, 103, 144, 215, 43, 81, 67, 28, 230, 195, 85, 96, 243, 174, 248, 77, 173, 188,
                 7, 224, 10, 171, 19, 177, 64, 194, 214, 23, 78
    };
    //int ar2[] = {100, 203, 184, 5, 10, 84, 209, 0, 74, 97, 225, 232, 187, 113, 214, 141, 125, 131, 254, 200, 132, 210, 240, 164, 13, 130, 51, 201, 121, 63, 249, 162, 120, 202, 148, 36, 45, 1, 171, 65, 20, 80, 59, 56, 186, 192, 153, 138, 124, 126, 39, 196, 27, 238, 82, 144, 237, 221, 11, 110, 47, 103, 18, 14, 243, 251, 55, 25, 28, 33, 68, 147, 96, 35, 93, 142, 29, 73, 106, 234, 108, 90, 64, 151, 111, 253, 78, 158, 152, 43, 7, 182, 167, 4, 218, 231, 112, 72, 248, 6, 91, 178, 52, 57, 69, 145, 37, 79, 181, 247, 143, 67, 198, 241, 205, 155, 161, 92, 134, 246, 24, 137, 177, 170, 199, 15, 149, 105, 49, 174, 53, 8, 83, 107, 70, 189, 197, 71, 195, 109, 233, 98, 156, 66, 2, 213, 166, 19, 60, 204, 250, 183, 168, 239, 212, 87, 222, 54, 31, 154, 104, 163, 230, 129, 215, 191, 3, 219, 127, 185, 173, 188, 117, 88, 136, 46, 44, 176, 242, 227, 180, 58, 128, 34, 62, 21, 99, 235, 32, 206, 226, 16, 255, 157, 114, 236, 42, 75, 81, 17, 101, 223, 146, 102, 76, 135, 207, 245, 216, 165, 217, 40, 228, 77, 61, 38, 94, 95, 150, 123, 190, 194, 86, 85, 172, 115, 50, 179, 48, 89, 160, 244, 26, 12, 229, 175, 140, 30, 41, 252, 119, 193, 22, 118, 133, 208, 169, 211, 116, 220, 122, 9, 139, 159, 224, 23};
    //int ar2[] = {3, 106, 87, 164, 169, 243, 112, 241, 109, 0, 128, 135, 90, 16, 129, 44, 28, 34, 157, 103, 35, 113, 143, 67, 172, 33, 210, 104, 24, 222, 152, 65, 23, 105, 51, 195, 204, 160, 74, 224, 179, 239, 218, 215, 197, 85, 56, 41, 27, 29, 198, 99, 186, 141, 155, 47, 140, 124, 170, 13, 206, 6, 177, 173, 146, 154, 214, 184, 187, 192, 227, 50, 255, 194, 233, 45, 188, 232, 9, 95, 11, 249, 223, 54, 14, 156, 237, 61, 55, 202, 166, 117, 70, 163, 121, 134, 15, 231, 151, 165, 250, 81, 211, 216, 228, 48, 196, 238, 84, 150, 46, 226, 101, 144, 108, 58, 64, 251, 37, 149, 183, 40, 252, 73, 102, 174, 52, 8, 208, 77, 212, 167, 242, 10, 229, 92, 100, 230, 98, 12, 136, 1, 59, 225, 161, 116, 69, 178, 219, 107, 153, 86, 71, 142, 115, 246, 125, 213, 190, 57, 7, 66, 133, 32, 118, 94, 162, 122, 30, 88, 76, 148, 20, 247, 39, 205, 203, 79, 145, 130, 83, 217, 31, 193, 221, 180, 2, 138, 191, 89, 137, 175, 158, 60, 17, 139, 201, 234, 240, 176, 4, 126, 49, 5, 235, 38, 110, 80, 119, 68, 120, 199, 131, 236, 220, 159, 253, 254, 53, 26, 93, 97, 245, 244, 75, 18, 209, 82, 207, 248, 63, 147, 185, 171, 132, 78, 43, 189, 200, 91, 22, 96, 181, 21, 36, 111, 72, 114, 19, 123, 25, 168, 42, 62, 127, 182 };
    int res = deltaUniformity(ar2, size, n);

    printf("\nDelta Uniformity = %d ", res);
    printf("\n");
    printf("\n");

    /*int mdt = differenceTableMax(ar2, size);

    printf("DT MAX = %d ", mdt);
    printf("\n");
    printf("\n");*/

    int LAT = LATMax(ar2, size, n);

    printf("LAT Max = %d ", LAT);
    printf("\n");

    int NL = raiseToPower(2, n - 1) - LAT;
    printf("Non-linearity from LAT = %d ", NL);
    printf("\n");

    int cs = cyclicStructure(ar2, size);
    printf("\nCycle = %d ", cs);
    printf("\n");

    int fp = fixedPoints(ar2, size);
    printf("\n");
    printf("\n");

    int md = minDegree(ar2, size, n);

    //int md = get_min_degree(ar2);

    printf("Minimal algebraic degree = %d ", md);
    printf("\n");

    int ai = algebraicImmunity(ar2, size, n);

    printf("\nAlgebraic Immunity = %d ", ai);
    printf("\n");

    //int sbl[] = {3, 106, 87, 164, 169, 243, 112, 241, 109, 0, 128, 135, 90, 16, 129, 44, 28, 34, 157, 103, 35, 113, 143, 67, 172, 33, 210, 104, 24, 222, 152, 65, 23, 105, 51, 195, 204, 160, 74, 224, 179, 239, 218, 215, 197, 85, 56, 41, 27, 29, 198, 99, 186, 141, 155, 47, 140, 124, 170, 13, 206, 6, 177, 173, 146, 154, 214, 184, 187, 192, 227, 50, 255, 194, 233, 45, 188, 232, 9, 95, 11, 249, 223, 54, 14, 156, 237, 61, 55, 202, 166, 117, 70, 163, 121, 134, 15, 231, 151, 165, 250, 81, 211, 216, 228, 48, 196, 238, 84, 150, 46, 226, 101, 144, 108, 58, 64, 251, 37, 149, 183, 40, 252, 73, 102, 174, 52, 8, 208, 77, 212, 167, 242, 10, 229, 92, 100, 230, 98, 12, 136, 1, 59, 225, 161, 116, 69, 178, 219, 107, 153, 86, 71, 142, 115, 246, 125, 213, 190, 57, 7, 66, 133, 32, 118, 94, 162, 122, 30, 88, 76, 148, 20, 247, 39, 205, 203, 79, 145, 130, 83, 217, 31, 193, 221, 180, 2, 138, 191, 89, 137, 175, 158, 60, 17, 139, 201, 234, 240, 176, 4, 126, 49, 5, 235, 38, 110, 80, 119, 68, 120, 199, 131, 236, 220, 159, 253, 254, 53, 26, 93, 97, 245, 244, 75, 18, 209, 82, 207, 248, 63, 147, 185, 171, 132, 78, 43, 189, 200, 91, 22, 96, 181, 21, 36, 111, 72, 114, 19, 123, 25, 168, 42, 62, 127, 182};

    //int ACofS = ACOfSBox(ar12, 8, 3);

    //printf("\n");

    //printf("AC = %d ", ACofS);

    /*int *ar13 = simulatedAnnealing(ar12,size,n);
    clock_t toc = clock();

    printf("Elapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);

    for (int i = 0; i < size; ++i) {
        printf("%d ", ar13[i]);
    }

    free(ar12);
    free(ar13);*/


    //int *psb = propertiesOfSBox(ar12,8,3);

    //int NLofS = NLOfSBox(ar12,256,8);

    //int ACofS = ACOfSBox(ar12, 8, 3);

    //printf("\n");

    //printf("NL = %d ", NLofS);
    //printf("AC = %d ", ACofS);

    /*int cost = costFunction(ar12,8,3);
    printf("\n");
    printf("\nCOST OF S-BOX IS\n");
    printf("%d ", cost);
    printf("\n");*/


    //free(binElems);
    //free(ar);
    //free(ar3);
    //free(ar4);
    //free(ar5);
    //free(ar6);
    //free(ar8);
    //free(fxarr);
    //free(WHT1Plus);
    //free(WHT2Plus);
    //free(WHT1Minus);
    //free(WHT2Minus);
    //free(ar9);

    return 0;
}

//Ôóíêö³ÿ ïðèâåäåííÿ ÷èñëà çà ìîäóëåì äóÿêîãî ÷èñëà

int myModulus(int number, int mod) {
    if (number < 0) {
        while (number < 0) {
            number = number + mod;
        }
    }
    return number % 2;
}

//Ôóíêö³ÿ ïåðåòâîðåííÿ åëåìåíò³â ç äåñÿòêîâî¿ Ñ× ó äâ³éêîâó Ñ×, äëÿ ïåâíîãî ñòóïåíÿ N

int *binaryElements(int *arr, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            result[j * size + i] = bin[k];
        }
        free(bin);
    }
    return result;
}

//Ôóíêö³ÿ ïåðåòâîðåííÿ ìàñèâó ÷èñåë ó äâ³éêîâ³é ñèñòåì³ äî òàáëèö³ ³ñòèíîñò³

int *massToBooleanFunc(int *arr, int *arr2, int size, int count, int t) {
    int calc;
    int calc2 = 1;
    //printf("\n");
    //printf("t = %d", t);
    //printf("\n");
    int *calculation = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = 0, k = count - 1; j < count; ++j, k--) {
            //printf("\n");
            //printf("bin k = %d", bin[k]);
            //printf("\n");
            //printf("arr2 i = %d", arr2[j*size+t]);
            calc = raiseToPower(arr2[j * size + t], bin[k]);
            //printf("\n");
            //printf("raised to power = %d", calc);
            //printf("%d\n",bin[j]);
            calc2 = calc2 * calc;
            //printf("\n");
            //printf("calc2 = %d", calc2);
            calculation[arr[i]] = calc2;
        }
        calc2 = 1;
        /*for (int r = 0; r<size; ++r){
            if(arr3[r]!=0){
                printf(" rrr %d", calculation[r]);
                calc3 = calc3^calculation[r];
                printf("\n");
                printf("calc3 = %d", calc3);
            }
        }*/
        //printf("\n");
        //printf("calc3 = %d", calc3);
        //printf("\n");
    }
    return calculation;
}

//Ôóíêö³ÿ ïåðåòâîðåííÿ ÷èñëà ç äåñÿòêîâî¿ Ñ× ó äâ³éêîâó Ñ×

int *valueToBinary(int i, int rank) {
    int *res = calloc(rank, sizeof(int));
    for (int j = 0; j < rank; ++j) {
        res[rank - 1 - j] = i >> j & 1;
    }
    return res;
}

//Ôóíêö³ÿ çâåäåííÿ äî ñòóïåíÿ

int raiseToPower(int num, int pow) {
    int res = 1;
    for (int i = 0; i < pow; ++i) {
        res *= num;
    }
    return res;
}

//Ôóíêö³ÿ ãåíåðàö³¿ ÷èñåë äëÿ âõ³äíèõ âåêòîð³â ñòóïåíÿ N

int *elemsForN(int size) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = i;
    }
    return result;
}

//Ôóíêö³ÿ ïåðåâåäåííÿ ç òàáëèö³ ³ñòèíîñò³ äî ÀÍÔ

int *toANF(const int *func, int size) {
    int *matrix = calloc(size * size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        matrix[i] = func[size - 1 - i];
    }
    /*for (int k = 0; k < size; ++k) {
        for (int l = 0; l < size; ++l) {
            printf(" %d", matrix[k*size+l]);
        }
        printf("\n");
    }*/
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            matrix[i * size + j] = (matrix[size * (i - 1) + j] + matrix[size * (i - 1) + (j + 1)]) % 2;
            //printf(" %d", matrix[i * size + j]);
        }
        //printf("\n");
    }
    int *coefficients = malloc(size * sizeof(int));
    for (int i = 0; i < size; ++i) {
        coefficients[i] = matrix[i * size];
    }
    free(matrix);
    return coefficients;
}

//Ôóíêö³ÿ îá÷èñëåííÿ âàãè Õåìì³íãà

int HammingWeight(const int *function, int size) {
    int weight = 0;
    for (int i = 0; i < size; ++i) {
        if (function[i]) {
            weight++;
        }
    }
    return weight;
}

//Ôóíêö³ÿ âèçíà÷åííÿ çáàëàíñîâàíîñò³ ôóíêö³¿

int funcIsBalanced(int weight, int pow) {
    int flag = 1;
    if (weight == raiseToPower(2, pow - 1)) {
        //printf("\nFunction is BALANCED!");
        return flag;
    } else {
        //printf("\nFunction is NOT BALANCED!");
        flag = 0;
        return flag;
    }
}

//Ôóíêö³ÿ âèçíà÷åííÿ àëãåáðà¿÷íîãî ñòóïåíÿ ôóíêö³¿

int algebraicDeg(const int *func, int size, int count) {
    int result;
    int flag = 0;
    int k = 0;
    int highestDec;
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        if (func[i]) {
            newSize++;
        }
    }
    //printf("\n newSize  = %d",newSize);
    int *deg = calloc(newSize, sizeof(int));
    for (int i = 0; i < size; ++i) {
        if (func[i]) {
            //printf("\ni = %d",i);
            int *bin = valueToBinary(i, count);
            for (int j = 0; j < count; ++j) {
                if (bin[j] == 1) {
                    ++flag;
                }
            }
            deg[k] = flag;
            //printf("\n deg k  = %d",deg[k]);
            flag = 0;
            ++k;
        }
    }
    highestDec = deg[0];
    for (int l = 0; l < newSize; ++l) {
        if (deg[l] > highestDec) {
            highestDec = deg[l];
        }
    }
    //printf("\nH deg   = %d",highestDec);
    result = highestDec;
    free(deg);
    return result;
}

//Ôóíêö³ÿ âèçíà÷åííÿ â³äñòàí³ Õåì³íãà

int HammingDistance(const int *func1, const int *func2, int size) {
    int res = 0;
    for (int i = 0; i < size; ++i) {
        if ((func1[i] ^ func2[i]) != 0) res++;
    }
    return res;
}

//Ôóíêö³ÿ âèçíà÷åííÿ ð³âíîñò³ ì³æ ôóíêö³ÿìè

int funcsIsEqual(const int *func1, const int *func2, int size) {
    int flag = 0;
    for (int i = 0; i < size; ++i) {
        if (func1[i] == func2[i]) {
            flag++;
        }
    }
    return flag == size;
}

//Ôóíêö³ÿ âèçíà÷åííÿ íåë³í³éíîñò³ ôóíêö³¿

int NLinearity(int *func, int size, int count) {
    int minimumNL;
    int minimumNL1;
    int minimumNL2;
    int matrixColumns = size;
    int matrixRows = raiseToPower(2, matrixColumns);
    int *functions = calloc(matrixRows * matrixColumns, sizeof(int));
    int *functions2 = elemsForN(matrixRows);
    int *testfunc = calloc(size, sizeof(int));
    /*for (int i = 0; i < matrixRows; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    //printf("\n");
    for (int i = 0; i < matrixRows; ++i) {
        int *bin = valueToBinary(functions2[i], matrixColumns);
        for (int j = 0; j < matrixColumns; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            functions[i * matrixColumns + j] = bin[j];
            //printf(" %d",functions [i * matrixColumns + j]);
        }
        //printf("\n");
    }
    //minimumNL = HammingDistance(func, functions, size);
    minimumNL1 = HammingDistance(func, functions, size);
    int *bin = valueToBinary(matrixRows - 1, matrixColumns);
    for (int j = 0; j < matrixColumns; ++j) {
        testfunc[j] = bin[j];
    }
    /*for (int i = 0; i < size; ++i) {
        printf(" %d",testfunc[i]);
    }*/
    //printf(" %d",minimumNL1);
    minimumNL2 = HammingDistance(func, testfunc, size);
    minimumNL = minimumNL1;
    if (minimumNL2 < minimumNL1) {
        minimumNL = minimumNL2;
    }
    for (int i = 0; i < matrixRows; ++i) {
        if (algebraicDeg(functions + matrixColumns * i, size, count) <= 1 &&
            !funcsIsEqual(func, functions + matrixColumns * i, size)) {
            int newMinHD = HammingDistance(func, functions + matrixColumns * i, matrixColumns);
            //printf(" NEW MID HD%d",newMinHD);
            if (newMinHD < minimumNL) {
                minimumNL = newMinHD;
            }
        }
    }
    int result = minimumNL;
    free(functions);
    free(functions2);
    free(testfunc);
    free(bin);
    return result;
}

//Ôóíêö³ÿ ïðåäñòàâëåííÿ òàáëèö³ ³ñòèíîñò³ â ïîëÿðíîìó âèãëÿä³

int *toPolarTable(const int *function, int size) {
    int *res = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        res[i] = raiseToPower(-1, function[i]);
    }
    return res;
}

//Ôóíêö³ÿ âèçíà÷åííÿ êîåô³ö³ºíò³â ïåðåòâîðåííÿ Óîëäøà-Àäàìàðà

int *HadamardCoefficients(const int *func, int size, int count) {
    int *result = calloc(size, sizeof(int));
    int *test = calloc(size * count, sizeof(int));
    int *functions2 = elemsForN(size);
    /*for (int i = 0; i < size; ++i) {
        printf(" %d",functions2 [i]);
    }*/
    //printf("\n");
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(functions2[i], count);
        for (int j = 0; j < count; ++j) {
            //printf(" bin j = %d", bin[j]);
            //*(functions + i * cols + j) = (i >> cols - j - 1) & 1u;
            test[i * count + j] = bin[j];
            //printf(" %d",test [i * count + j]);
        }
        //printf("\n");
        free(bin);
    }
    int *w = calloc(count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < count; ++j) {
            w[j] = test[i * count + j];
            //printf("w = %d", w[j]);
        }
        int res = 0;
        for (int j = 0; j < size; ++j) {
            int r = 0;
            for (int k = 0; k < count; ++k) {
                r += myModulus(w[k] * test[j * count + k], 2);
            }
            res += raiseToPower(-1, myModulus(func[j] + r, 2));
        }
        result[i] = res;
    }
    free(test);
    free(functions2);
    free(w);
    return result;
}

//Ôóíêö³ÿ âèçíà÷åííÿ íàéá³ëüøîãî êîåô³ö³ºíòà ïåðåòâîðåííÿ Óîëäøà-Àäàìàðà

int HadamardMax(const int *arr, int size) {
    int maxCoefficient = abs(arr[0]);
    for (int i = 0; i < size; ++i) {
        if (abs(arr[i]) > abs(maxCoefficient)) {
            maxCoefficient = abs(arr[i]);
        }
    }
    //printf("max coef %d", maxCoefficient);
    return maxCoefficient;
}

//Ôóíêö³ÿ âèçíà÷åííÿ íåë³í³éíîñò³ ôóíêö³¿ ÷åðåç êîåô³ö³ºíòè Óîëäøà-Àäàìàðà

int HadamardNLinearity(int max, int count) {
    int nl = (raiseToPower(2, count) - max) / 2;
    return nl;
}

//Ôóíêö³ÿ îá÷èñëåííÿ àâòîêîðåëÿö³éíî¿ ôóíêö³¿

int *autoCorrelation(int *func, int size, int count) {
    int *acFunc = calloc(size, sizeof(int));
    int *polFunc = toPolarTable(func, size);
    acFunc[0] = raiseToPower(2, count);
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int temp = polFunc[j] * polFunc[j ^ i];
            //printf("j^i = %d", j^i);
            acFunc[i] = acFunc[i] + temp;
        }
        //printf("ac i = %d", acFunc[i]);
    }
    free(polFunc);
    return acFunc;
}

//Ôóíêö³ÿ îá÷èñëåííÿ àâòîêîðåëÿö³¿ ç ôóíêö³¿ àâòîêîðåëÿö³¿

int autoCorrelationMax(const int *arr, int size) {
    int maxCoefficient = abs(arr[1]);
    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) > maxCoefficient) {
            maxCoefficient = abs(arr[i]);
        }
    }
    return maxCoefficient;
}

//Ôóíêö³ÿ âèçíà÷åííÿ â³äïîâ³äíîñò³ êðèòåð³ÿì

int expansionCriterion(const int *func, int size, int k) {
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += func[i] ^ func[i ^ k];
    }
    if (result == size / 2) {
        printf("\nComply with Criterion KP(%d)", k);
    } else {
        printf("\nNot comply with Criterion KP(%d)", k);
    }
    return result;
}

//Ôóíêö³ÿ âèçíà÷åííÿ ìíîæèíè W1+

int *WHT1PlusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == max) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Ôóíêö³ÿ âèçíà÷åííÿ ìíîæèíè W1-

int *WHT1MinusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == -max) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Ôóíêö³ÿ âèçíà÷åííÿ ìíîæèíè W2+

int *WHT2PlusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == (max - 2)) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Ôóíêö³ÿ âèçíà÷åííÿ ìíîæèíè W2-

int *WHT2MinusSet(const int *func, int size, int newSize, int max) {
    if (newSize != 0) {
        int *result = calloc(newSize, sizeof(int));
        int k = 0;
        for (int j = 0; j < size; ++j) {
            if (func[j] == -(max - 2)) {
                result[k] = j;
                k++;
            }
        }
        return result;
    } else {
        return NULL;
    }
}

//Ôóíêö³ÿ âèêîíàííÿ îïåðàö³¿ "îá'ºäíàííÿ" íàä ìàñèâàìè

int arrayUnion(const int a[], int n1, const int b[], int n2, int c[]) {
    int n = 0, i = 0, j = 0;

    while ((i < n1) && (j < n2)) {
        if (a[i] < b[j])
            c[n++] = a[i++];
        else if (a[i] > b[j])
            c[n++] = b[j++];
        else {
            c[n++] = a[i++];
            ++j;
        }
    }

    while (i < n1)
        c[n++] = a[i++];
    while (j < n2)
        c[n++] = b[j++];
    return n;
}

//Ôóíêö³ÿ îá÷èñëåííÿ ë³í³éíî¿ ôóíêö³¿ äëÿ çàäàíîãî îìåãà

int *linearFunctions(int size, int count, int t) {
    int calc1 = 0;
    int calc2 = 0;
    int sum = 0;
    int *binElems = elemsForN(size);
    int *ar = binaryElements(binElems, size, count);
    int *bin = valueToBinary(t, count);
    /*for (int i = 0; i < count; ++i) {
        printf("%d ", bin[i]);
    }*/
    //printf("\n");
    int *result = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        for (int i = 0, k = count - 1; i < count, k >= 0; ++i, --k) {
            calc1 = ar[i * size + j] * bin[k];
            //printf("%d ", bin[k]);
            //printf("%d ", calc1);
            sum = sum ^ calc1;
            //printf("%d ", sum);
        }
        //printf("%d ", sum);
        result[j] = sum;
        sum = 0;
        //printf("\n");
    }
    free(binElems);
    free(bin);
    free(ar);
    return result;
}

//Ôóíêö³ÿ ç'ºäíàííÿ äâîõ ìàñèâ³â

int *arrayAdd(const int *arr1, int size1, const int *arr2, int size2) {
    int linearMassSize = size1 + size2;
    int *result = calloc(linearMassSize, sizeof(int));
    for (int i = 0; i < size1; ++i) {
        result[i] = arr1[i];
    }
    if (size2 != 0) {
        for (int j = 0; j < size2; ++j) {
            result[j + size1] = arr2[j];
        }
    }
    return result;
}

//Ôóíêö³ÿ çíàõîäæåííÿ íàáîðó ïîêðàùåíü

int *improvementSet(const int func[], const int *linearFunctions, int size, int linearMassSize, int WHTPlusSize) {
    int counter = 0;
    int k = 0;
    int flag = 1;
    int *result = calloc(size, sizeof(int));
    int *result1 = calloc(size, sizeof(int));
    int *result2 = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < WHTPlusSize; ++i) {
            if ((func[j] == linearFunctions[i * size + j])) {
                flag = 1;
            } else {
                flag = 0;
                break;
            }
        }
        //printf("flag %d ", flag);
        if (flag == 1) {
            result1[j] = 1;
        } else {
            result1[j] = 0;
        }

    }
    /*for (int j = 0; j < size; ++j) {
        printf("%d ", result1[j]);
    }*/
    if (WHTPlusSize < linearMassSize) {
        for (int j = 0; j < size; ++j) {
            for (int i = WHTPlusSize; i < linearMassSize; ++i) {
                if ((func[j] != linearFunctions[i * size + j])) {
                    flag = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
            //printf("flag %d ", flag);
            if (flag == 1) {
                result2[j] = 1;
            } else {
                result2[j] = 0;
            }

        }
        /*for (int j = 0; j < size; ++j) {
            printf("%d ", result2[j]);
        }*/
        for (int j = 0; j < size; ++j) {
            if ((result1[j] == 1) && (result2[j] == 1) && (result1[j] == result2[j])) {
                result[j] = 1;
            } else {
                result[j] = 0;
            }
        }
    } else {
        for (int j = 0; j < size; ++j) {
            result[j] = result1[j];
        }
    }
    for (int j = 0; j < size; ++j) {
        if (result[j] == 1) {
            counter++;
        }
    }
    if (counter == 0) {
        printf("\nIMPROVEMENT IS UNAVAILABLE");
    }

    free(result1);
    free(result2);
    return result;
}

//Ôóíêö³ÿ ï³äâèùåííÿ íåë³í³éíîñò³ ìåòîäîì Ãðàä³ºíòíîãî Ï³äéîìó

int *HillClimbing(const int f[], const int *improvementSet, int size, int count) {
    int *ftemp = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            ftemp[j] = f[j];
        }
        if (improvementSet[i] == 1) {
            if (ftemp[i] == 0) {
                ftemp[i] = 1;
            } else {
                ftemp[i] = 0;
            }
            printf("\n|---------------------------------|");
            printf("\nCHANGED COEFFICIENT NUMBER %d ", i);
            printf("\n");
            printf("\nNEW TRUTH TABLE");
            printf("\n");
            for (int k = 0; k < size; ++k) {
                printf("%d ", ftemp[k]);
            }
            int *farr = HadamardCoefficients(ftemp, size, count);
            printf("\nNEW HADAMARD COEFFICIENTS");
            printf("\n");
            for (int l = 0; l < size; ++l) {
                printf("%d ", farr[l]);
            }
            int max = HadamardMax(farr, size);
            //printf("\n max = %d", max);
            int nl = HadamardNLinearity(max, count);
            printf("\n");
            printf("\nNEW HADAMARD NON LINEARITY = %d", nl);
            printf("\n");
            free(farr);
            return ftemp;
            break;
        }
    }
}

//Ôóíêö³ÿ öèêë³÷íîãî ï³äâèùåííÿ íåë³í³éíîñò³ ôóíêö³¿ ìåòîäîì Ãðàä³ºíòíîãî Ï³äéîìó, ïîêè öå ìîæëèâî

int *roundableHillClimbing(const int f[], int size, int count) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        result[i] = f[i];
    }
    int counter = 0;
    while (counter < 1) {
        int weight;
        weight = HammingWeight(result, size);
        int flag = funcIsBalanced(weight, count);
        printf("\n");
        printf("\nTRUTH TABLE");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", result[i]);
        }
        int *fxarr = HadamardCoefficients(result, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", fxarr[i]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");

        int sizeWHT1P = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == max1) {
                sizeWHT1P++;
            }
        }

        printf("\nW1 PLUS");
        printf("\n");
        int *WHT1Plus = WHT1PlusSet(fxarr, size, sizeWHT1P, max1);
        if (WHT1Plus) {
            for (int i = 0; i < sizeWHT1P; ++i) {
                printf("%d ", WHT1Plus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT1M = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == -max1) {
                sizeWHT1M++;
            }
        }

        printf("\nW1 MINUS");
        printf("\n");
        int *WHT1Minus = WHT1MinusSet(fxarr, size, sizeWHT1M, max1);
        if (WHT1Minus) {
            for (int i = 0; i < sizeWHT1M; ++i) {
                printf("%d ", WHT1Minus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT2P = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == (max1 - 2)) {
                sizeWHT2P++;
            }
        }

        printf("\nW2 PLUS");
        printf("\n");
        int *WHT2Plus = WHT2PlusSet(fxarr, size, sizeWHT2P, max1);
        if (WHT2Plus) {
            for (int i = 0; i < sizeWHT2P; ++i) {
                printf("%d ", WHT2Plus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        int sizeWHT2M = 0;
        for (int i = 0; i < size; ++i) {
            if (fxarr[i] == (max1 - 2)) {
                sizeWHT2M++;
            }
        }

        printf("\nW2 MINUS");
        printf("\n");
        int *WHT2Minus = WHT2MinusSet(fxarr, size, sizeWHT2M, max1);
        if (WHT2Minus) {
            for (int i = 0; i < sizeWHT2M; ++i) {
                printf("%d ", WHT2Minus[i]);
            }
        } else {
            printf("NULL");
        }
        printf("\n");

        // Îòðèìàííÿ îá'ºäíàííÿ WHT1P òà WHT2P
        if (!WHT1Plus && !WHT2Plus) {
            printf("SET WHT PLUS IS NULL");
        } else {
            int c1[(sizeWHT1P + sizeWHT2P)];
            //printf("%d ", (sizeWHT1P + sizeWHT1P));

            int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
            printf("\nSET WHT PLUS");
            printf("\n");
            for (int i = 0; i < m1; ++i) {
                printf("%d ", c1[i]);
            }
        }

        printf("\n");

        // Îòðèìàííÿ îá'ºäíàííÿ WHT1M òà WHT2M
        if (!WHT1Minus && !WHT2Minus) {
            printf("\nSET WHT MINUS IS NULL");
        } else {
            int c2[(sizeWHT1M + sizeWHT2M)];
            //printf("%d ", (sizeWHT1P + sizeWHT1P));

            int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);
            printf("\nSET WHT MINUS");
            printf("\n");
            for (int i = 0; i < m2; ++i) {
                printf("%d ", c2[i]);
            }
        }

        printf("\n");

        /*int *ar7 = linearFunctions(size, n, 5);
        printf("\nLINEAR FUNCTION");
        printf("\n");
        for (int i = 0; i < size; ++i) {
            printf("%d ", ar7[i]);
        }
        printf("\n");*/

        int c1[(sizeWHT1P + sizeWHT2P)];
        int c2[(sizeWHT1M + sizeWHT2M)];
        int m1 = arrayUnion(WHT1Plus, sizeWHT1P, WHT2Plus, sizeWHT2P, c1);
        int m2 = arrayUnion(WHT1Minus, sizeWHT1M, WHT2Minus, sizeWHT2M, c2);

        //printf("%d ", m1);
        //printf("%d ", m2);

        int linearMassSize = m1 + m2;
        /*int c3[1] = {7};
        int c[linearMassSize];
        for (int i = 0; i < m1; ++i) {
                c[i] = c1[i];
        }
        if (m2!=0) {
            for (int j = 0; j < m2; ++j) {
                c[j + m1] = c3[j];
            }
        }*/

        int *c = arrayAdd(c1, m1, c2, m2);
        printf("Linear mass size %d ", linearMassSize);
        printf("\nOMEGA LINEAR FUNCTIONS TO FIND");
        printf("\n");
        for (int i = 0; i < linearMassSize; ++i) {
            printf("%d ", c[i]);
        }
        printf("\n");

        int *linearFunctionsMass = calloc(linearMassSize * size, sizeof(int));
        for (int i = 0; i < linearMassSize; ++i) {
            int t = c[i];
            int *arr = linearFunctions(size, count, t);
            for (int j = 0; j < size; ++j) {
                //printf("%d ", arr[j]);
                linearFunctionsMass[i * size + j] = arr[j];
                printf("%d ", linearFunctionsMass[j]);
            }
        }

        printf("\nLINEAR FUNCTIONS");
        printf("\n");

        for (int i = 0; i < linearMassSize; ++i) {
            for (int j = 0; j < size; ++j) {
                printf("%d ", linearFunctionsMass[i * size + j]);
            }
            printf("\n");
        }


        printf("\nIMPROVEMENT SET:");
        int *ar8 = improvementSet(result, linearFunctionsMass, size, linearMassSize, m1);
        int k = 0;
        printf("\n");
        for (int j = 0; j < size; ++j) {
            printf("%d ", ar8[j]);
            if (ar8[j] != 0) {
                k++;
            }
        }
        if (k == 0) {
            counter = 1;
            //printf("counter %d ", counter);
            int *nonLin = calloc(1, sizeof(int));
            nonLin[0] = nl2;
            return nonLin;
            break;
        }

        int *ar9 = HillClimbing(result, ar8, size, count);
        printf("\n");
        for (int j = 0; j < size; ++j) {
            result[j] = ar9[j];
            //printf("%d ", result[j]);
        }
        free(fxarr);
        free(WHT1Plus);
        free(WHT1Minus);
        free(WHT2Plus);
        free(WHT2Minus);
        free(c);
        free(linearFunctionsMass);
        free(ar8);
        free(ar9);
    }

    return result;
}

//Ôóíêö³ÿ ïåðåòâîðåííÿ âõ³äíîãî S-Box íà íàá³ð áóëåâèõ ôóíêö³é, ùî éîãî îïèñóþòü

int *SBoxToBooleanFunc(int *sbox, int size, int count) {
    //printf("\nS-BOX\n");
    /*for (int i = 0; i < size; ++i) {
        printf("%d ", sbox[i]);
    }*/
    //printf("\n");
    //printf("\nS-BOX IN BOOLEAN FUNCTIONS REPRESENTATION\n");
    int *result = binaryElements(sbox, size, count);
    /*for (int i = 0; i < count; ++i) {
        printf("Function %d = ", i + 1);
        for (int j = 0; j < size; ++j) {
            printf("%d ", result[i * size + j]);
        }
        printf("\n");
    }*/

    //printf("\n");

    /*for (int i = 0; i < count; ++i) {
         int *temp = calloc(size, sizeof(int));
         //printf("Function %d", i);
         for (int j = 0; j < size; ++j) {
             temp[j] = result[i * size + j];
         }
         int weight = HammingWeight(temp, size);
         int flag = funcIsBalanced(weight, count);
         //printf("\n");
         free(temp);
     }*/
    return result;
}

//Ôóíêö³ÿ ïåðåòâîðåííÿ íàáîðó áóëåâèõ ôóíêö³é íà S-Box

int *booleanFunctionsToSBox(const int *arr, int size, int count) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < count; ++j) {
            result[i] += arr[j * size + i] * raiseToPower(2, j);
        }
    }
    return result;
}

//Ôóíêö³ÿ çíàõîäæåííÿ ïîêàçíèê³â áóëåâèõ ôóíêö³é S-Box'ó

int *propertiesOfBooleanFunc(int *arr, int size, int count) {
    printf("\nFUNCTIONS PROPERTIES\n");
    for (int i = 0; i < count; ++i) {
        int *temp = calloc(size, sizeof(int));
        printf("\nFunction %d", i);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int weight = HammingWeight(temp, size);
        int flag = funcIsBalanced(weight, count);
        int *fxarr = HadamardCoefficients(temp, size, count);
        printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");
        int k = 1;
        int ec = expansionCriterion(temp, size, k);
        printf("\n");
        int *ar = autoCorrelation(temp, size, count);

        printf("\nAUTO CORRELATING FUNCTION");
        printf("\n");
        for (int w = size - 1; w >= 0; w--) {
            printf("%d ", ar[w]);
        }
        printf("\n");

        int AC = autoCorrelationMax(ar, size);
        printf("\nAUTO CORRELATION = %d", AC);
        printf("\n");
        int dec = algebraicDeg(temp, size, count);
        printf("\nALGEBRAIC DEGREE = %d ", dec);
        printf("\n");
    }
    return arr;
}

//Ôóíêö³ÿ çíàõîäæåííÿ ë³í³éíèõ êîìá³íàö³é äëÿ áóëåâèõ ôóíêö³é S-Box'ó

int *linearCombinations(const int *arr, int size, int count) {
    int *result = calloc(size * size, sizeof(int));
    int *calc = calloc(size, sizeof(int));
    for (int i = 1; i < size; ++i) {
        int *bin = valueToBinary(i, count);
        for (int j = 0, k = count - 1; j < count, k >= 0; ++j, k--) {
            if (bin[k] == 1) {
                for (int w = 0; w < size; ++w) {
                    calc[w] = calc[w] ^ arr[j * size + w];
                    //printf(" %d", arr[j*size]);
                    //printf(" %d", j * size + k);
                    //printf("calc =  %d", calc[k]);
                    //result[(i-1)*size+k] = calc[k];
                    //printf("result  =  %d", (i-1)*size+k);
                }
                //printf("\n");
            }
            for (int r = 0; r < size; ++r) {
                result[(i - 1) * size + r] = calc[r];
            }
            //printf(" %d", bin[j]);
        }
        for (int l = 0; l < size; ++l) {
            //printf("calc =  %d", calc[l]);
            //result[(i-1) * size + l] = calc[l];
            calc[l] = 0;
        }
        //printf("\n");
        free(bin);
    }
    free(calc);
    return result;
}

//Ôóíêö³ÿ çíàõîäæåííÿ ïîêàçíèê³â ë³í³éíèõ êîìá³íàö³é äëÿ áóëåâèõ ôóíêö³é S-Box'ó òà çíàõîäæåííÿ ì³í³ìàëüíî¿ íåë³í³éíîñò³ ñåðåä íèõ

int *propertiesOfLinearCombinations(const int *arr, int size, int count) {
    int *minimalNL = calloc(size - 1, sizeof(int));
    int *maxAC = calloc(size - 1, sizeof(int));
    int *minDEC = calloc(size - 1, sizeof(int));
    int *result = calloc(4, sizeof(int));
    int balancedFlag = 1;
    //printf("\nLINEAR COMBINATIONS PROPERTIES\n");
    for (int i = 0; i < size - 1; ++i) {
        int *temp = calloc(size, sizeof(int));
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int weight = HammingWeight(temp, size);
        int flag = funcIsBalanced(weight, count);
        if (flag == balancedFlag) {
        } else {
            balancedFlag = flag;
        }
        int *fxarr = calloc(size, sizeof(int));
        fxarr = HadamardCoefficients(temp, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        int nl2 = HadamardNLinearity(max1, count);
        /*printf("\n");
        printf("\nHADAMARD NON LINEARITY = %d", nl2);
        printf("\n");*/
        minimalNL[i] = nl2;
        int k = 1;
        //int ec = expansionCriterion(temp, size, k);
        //printf("\n");
        int *ar = calloc(size, sizeof(int));
        ar = autoCorrelation(temp, size, count);

        /*printf("\nAUTO CORRELATING FUNCTION");
        printf("\n");
        for (int w = size - 1; w >= 0; w--) {
            printf("%d ", ar[w]);
        }
        printf("\n");*/

        int AC = autoCorrelationMax(ar, size);
        //printf("\nAUTO CORRELATION = %d", AC);
        //printf("\n");
        maxAC[i] = AC;
        int dec = algebraicDeg(temp, size, count);
        //printf("\nALGEBRAIC DEGREE = %d ", dec);
        //printf("\n");
        minDEC[i] = dec;
        free(temp);
        free(fxarr);
        free(ar);
    }
    int min = 0;
    min = minimalNL[0];
    //printf("\nNON-LINEARITIES ARRAY");
    //printf("\n");
    for (int r = 0; r < size - 1; ++r) {
        //printf("%d ", minimalNL[r]);
        if (minimalNL[r] < min) {
            min = minimalNL[r];
        }
    }
    int max = 0;
    max = maxAC[0];
    //printf("\nAC ARRAYS");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        //printf("%d ", maxAC[t]);
        if (maxAC[t] > max) {
            max = maxAC[t];
        }
    }
    int minD = 0;
    minD = minDEC[0];
    //printf("\nDEC ARRAY");
    //printf("\n");
    for (int y = 0; y < size - 1; ++y) {
        //printf("%d ", minDEC[y]);
        if (minDEC[y] < minD) {
            minD = minDEC[y];
        }
    }
    printf("\n");
    result[0] = min;
    result[1] = max;
    result[2] = minD;
    result[3] = balancedFlag;
    free(minimalNL);
    free(maxAC);
    free(minDEC);
    return result;
}

//Ôóíêö³ÿ ãåíåðàö³¿ S-Box'ó

int *SBoxGenerating(int n, int m) {
    int size = raiseToPower(2, n);
    int *dec = calloc(size, sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size;) {
        dec[i] = rand() % size;
        int contains = 0;
        for (int j = 0; j < i; ++j) {
            if (dec[i] == dec[j]) {
                contains = 1;
                break;
            }
        }
        if (!contains) {
            i++;
        }
    }
    printf("Generated s-box: ");
    for (int i = 0; i < size; ++i) {
        printf("%d ,", dec[i]);
    }
    printf("\n");
    int *sb = SBoxToBooleanFunc(dec, size, m);
    free(dec);
    return sb;
}

//Ôóíêö³ÿ çíàõîäæåííÿ âëàñòèâîéñòåé S-Box'ó

int *propertiesOfSBox(int *sbox, int size, int count) {
    int result;
    int *ar1 = linearCombinations(sbox, size, count);
    int *ar2 = propertiesOfLinearCombinations(ar1, size, count);
    printf("\nNON LINEARITY OF S-BOX IS\n");
    printf("%d ", ar2[0]);
    printf("\nAUTO CORRELATION OF S-BOX IS\n");
    printf("%d ", ar2[1]);
    printf("\nDEGREE OF S-BOX IS\n");
    printf("%d ", ar2[2]);
    //printf("%d ", ar2[3]);
    if (ar2[3] == 1) {
        printf("\nS-BOX IS BALANCED\n");
        result = 1;
    } else {
        printf("\nS-BOX IS NOT BALANCED\n");
        result = 1;
    }
    printf("\n");
    return ar2;
}

int NLOfSBox(const int *sbox, int size, int count) {
    int result;
    int *ar1 = linearCombinations(sbox, size, count);
    result = NLOfLinearCombinations(ar1, size, count);
    free(ar1);
    return result;
}

int ACOfSBox(int *sbox, int size, int count) {
    int result;
    int *ar1 = linearCombinations(sbox, size, count);
    int *ar2 = propertiesOfLinearCombinations(ar1, size, count);
    result = ar2[1];
    free(ar1);
    free(ar2);
    return result;
}

//Ôóíêö³ÿ "âàðòîñò³" S-Box'ó

int costFunction(int *sbox, int size, int count) {
    int *costArray = calloc(size - 1, sizeof(int));
    int *ar1 = linearCombinations(sbox, size, count);
    for (int i = 0; i < size - 1; ++i) {
        int *temp = calloc(size, sizeof(int));
        //printf("\nCombination %d", i+1);
        for (int j = 0; j < size; ++j) {
            temp[j] = ar1[i * size + j];
        }
        int *fxarr = HadamardCoefficients(temp, size, count);
        /*printf("\nHADAMARD COEFFICIENTS");
        printf("\n");
        for (int q = 0; q < size; ++q) {
            printf("%d ", fxarr[q]);
        }*/
        int max1 = HadamardMax(fxarr, size);
        //printf("\n max = %d", max1);
        costArray[i] = max1;
        free(fxarr);
        free(temp);
    }
    int cost;
    cost = costArray[0];
    //printf("\n");
    //printf("\nCOST ARRAY");
    //printf("\n");
    for (int t = 0; t < size - 1; ++t) {
        //printf("%d ", costArray[t]);
        if (costArray[t] > cost) {
            cost = costArray[t];
        }
    }
    free(costArray);
    free(ar1);
    return cost;
}

int *simulatedAnnealing(const int *sbox, int size, int count) {
    char *filename = "D:\\CLionProjects\\boolANF\\result.txt";
    FILE *fp;
    double T = 100;
    double a = 0.99;
    int MIL = 100;
    int MUL = 0;
    int SNL = 0;
    int flag;
    int fileCounter = 0;
    int NLStart = NLOfSBox(sbox, size, count);
    printf("NLStart ===%d ", NLStart);
    int *SBoxBest = calloc(size, sizeof(int));
    int *SB = calloc(size * count, sizeof(int));
    int *SY = calloc(size * count, sizeof(int));
    SBoxBest = booleanFunctionsToSBox(sbox, size, count);
    for (int i = 0; i < size; ++i) {
        //printf("%d ", SBoxBest[i]);
    }
    int *S = calloc(size, sizeof(int));
    for (int j = 0; j < size; ++j) {
        S[j] = SBoxBest[j];
    }
    int first = rand() % (size);
    int second = rand() % (size);
    int counter = 0;
    int *Y = calloc(size, sizeof(int));
    while (SNL < 100) {
        counter++;
        for (int b = 0; b < MIL; ++b) {
            printf("%d ", b);
            if (first == second) {
                first = (first + rand() % (size)) % size;
            }
            srand(time(NULL));
            SB = SBoxToBooleanFunc(S, size, count);
            /*for (int i = 0; i < size*count; ++i) {
                printf("%d ", SB[i]);
            }*/
            int costOfPrevious = costFunction(SB, size, count);
            printf("COST OF OLD ===%d ", costOfPrevious);
            //int NLofS = NLOfSBox(SB, size, count);
            //printf("NL OF OLD ===%d ", NLofS);
            printf("\n");
            //printf("First = %d ", first);
            //printf("Second = %d ", second);
            for (int k = 0; k < size; ++k) {
                Y[k] = S[k];
            }
            int tmp = Y[first];
            Y[first] = Y[second];
            Y[second] = tmp;
            first = (first + Y[second]) % size;
            second = (second + Y[first]) % size;
            SY = SBoxToBooleanFunc(Y, size, count);
            int costOfNew = costFunction(SY, size, count);
            printf("COST OF NEW ===%d ", costOfNew);
            //int NLofNS = NLOfSBox(SY, size, count);
            //printf("NL OF NEW ===%d ", NLofNS);
            int delta = costOfNew - costOfPrevious;
            //printf("\nDelta ===%d ", delta);
            if (delta <= 0) {
                for (int l = 0; l < size * count; ++l) {
                    SB[l] = SY[l];
                    MUL = 0;
                    //printf("SB [j] ===%d ", SB[j]);
                }
            } else {
                ++MUL;
                //ãåíåðèðóåì ñëó÷àéíîå ÷èñëî 0..1
                srand(time(NULL));
                int N = 100;
                int rd = rand() % (N);
                //printf("\nrd ===%d ", rd);
                double u = (double) rd / N;
                //printf("\nu ===%lf\n ", u);
                double t = (double) delta / T;
                //printf("\ndt ===%lf\n ", exp(-t));
                if (u < exp(-t)) {
                    //printf("\nDT\n");
                    //ñ íåêîé âåðîÿòíîñòüþ ïðèíèìàåì õóäøåãî ïîòîìêà
                    for (int m = 0; m < size * count; ++m) {
                        SB[m] = SY[m];
                    }
                }
            }
            S = booleanFunctionsToSBox(SB, size, count);
            if (costOfNew <= 60) {
                ++fileCounter;
                if ((fp = fopen(filename, "a")) == NULL) {
                    printf("Error while opening file");
                }
                // записываем строку
                fprintf(fp, "\nS-BOX NUMBER");
                fprintf(fp, " %d:", fileCounter);
                for (int p = 0; p < size; ++p) {
                    fprintf(fp, "%d, ", S[p]);
                }
                fprintf(fp, "\n");
                fprintf(fp, "\nCOST OF S-BOX");
                fprintf(fp, " %d:", costOfNew);
                fprintf(fp, "\n");
                fprintf(fp, "\n");
                fclose(fp);   //закрываем файл
            }
            if (costOfNew <= 56) {
                break;
            }
            //printf("MUL ===%d ", MUL);
            if (MUL >= 30) {
                break;
            }
        }
        MUL = 0;
        T = T * a;
        /*for (int j = 0; j < size * count; ++j) {
            printf("%d ", SB[j]);
        }*/
        SNL = NLOfSBox(SB, size, count);
        printf("\nSNL ===%d ", SNL);
        printf("\nTemperature ===%lf ", T);
        printf("\nC==%d\n", counter);
        /*int SAC = ACOfSBox(SB, size, count);
        printf("SAC ===%d ", SAC);*/
    }
    free(Y);
    free(SY);
    free(SBoxBest);
    free(SB);
    return S;
}

int NLOfLinearCombinations(const int *arr, int size, int count) {
    int *minimalNL = calloc(size - 1, sizeof(int));
    int result;
    int *temp = calloc(size, sizeof(int));
    int *fxarr = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        fxarr = HadamardCoefficients(temp, size, count);
        int max1 = HadamardMax(fxarr, size);
        int nl2 = HadamardNLinearity(max1, count);
        minimalNL[i] = nl2;
    }
    int min = 0;
    min = minimalNL[0];
    //printf("\nNON-LINEARITIES ARRAY");
    //printf("\n");
    for (int r = 0; r < size - 1; ++r) {
        //printf("%d ", minimalNL[r]);
        if (minimalNL[r] < min) {
            min = minimalNL[r];
        }
    }
    result = min;
    free(minimalNL);
    free(temp);
    free(fxarr);
    return result;
}

int deltaUniformity(const int *arr, int size, int count) {
    int result;
    int max = 0;
    for (int a = 1; a < size; ++a) {
        for (int b = 0; b < size; ++b) {
            result = 0;
            for (int x = 0; x < size; ++x) {
                if ((arr[x] ^ arr[x ^ a]) == b) {
                    ++result;
                }
            }
            if (result > max) {
                max = result;
            }
        }

    }
    return max;
}

int differenceTableMax(const int *sbox, int size) {
    int *DDT = calloc(size * size, sizeof(int));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            DDT[i * size + j] = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            DDT[(i ^ j) * size + (sbox[i] ^ sbox[j])]++;
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", DDT[i * size + j]);
        }
        printf("\n");
    }
    int *findMax = DDT;
    int result = 0;
    for (int i = 1; i < size * size; i++) {
        if (findMax[i] > result)
            result = findMax[i];
    }
    free(DDT);
    free(findMax);
    return result;
}

int *binaryElementsApprox(int *arr, int size, int count) {
    int *result = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        int *bin = valueToBinary(arr[i], count);
        for (int j = count - 1; j >= 0; j--) {
            result[j * size + i] = bin[j];
        }
        free(bin);
    }
    return result;
}

int *SBoxApprox(int *sbox, int size, int count) {
    int *result = binaryElementsApprox(sbox, size, count);
    return result;
}

int LATMax(int *sbox, int size, int count) {
    int *ar = calloc(size * count, sizeof(int));
    ar = SBoxApprox(sbox, size, count);
    int *elems = elemsForN(size);
    int *binelems = binaryElementsApprox(elems, size, count);
    int *temp = calloc(size, sizeof(int));
    int *temp2 = calloc(size, sizeof(int));
    int *coefficients = calloc(size * size, sizeof(int));
    int *bin1 = calloc(count, sizeof(int));
    int *bin2 = calloc(count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        bin1 = valueToBinary(i, count);
        for (int k = count - 1; k >= 0; k--) {
            if (bin1[k]) {
                //printf("K===%d ",k);
                //printf("X == \n ");
                for (int l = 0; l < size; ++l) {
                    temp[l] = temp[l] ^ binelems[k * size + l];
                    //printf("%d ",temp[l]);
                }
                //printf("\n ");
            }
        }
        //printf("\n ");
        for (int j = 0; j < size; ++j) {
            bin2 = valueToBinary(j, count);
            for (int q = count - 1; q >= 0; q--) {
                if (bin2[q]) {
                    //printf("K===%d ",k);
                    //printf("\nY [%d]== \n ", j);
                    for (int w = 0; w < size; ++w) {
                        temp2[w] = temp2[w] ^ ar[q * size + w];
                        //printf("%d ",temp2[l]);
                    }
                }
            }
            //printf("\n ");
            int calc = 0;
            for (int r = 0; r < size; ++r) {
                temp2[r] = temp2[r] ^ temp[r];
                //printf("%d ", temp2[l]);
                if (temp2[r] == 0) {
                    ++calc;
                }
                temp2[r] = 0;
            }
            int result = 0;
            result = calc - (size / 2);
            //printf("COEFFS = %d ", result);
            coefficients[i * size + j] = result;

        }
        for (int t = 0; t < size; ++t) {
            temp[t] = 0;
        }
        //printf("\n ");
    }
    for (int n = 0; n < size; ++n) {
        for (int m = 0; m < size; ++m) {
            //printf("%d ", coefficients[n*size+m]);
        }
        //printf("\n");
    }
    int result = 0;
    for (int p = 1; p < size * size; p++) {
        if (abs(coefficients[p]) > result)
            result = abs(coefficients[p]);
    }
    free(ar);
    free(elems);
    free(binelems);
    free(temp);
    free(temp2);
    free(bin1);
    free(bin2);
    return result;
}

int cyclicStructure(const int *sbox, int size) {
    int *structure = calloc(size * 4, sizeof(int));
    int *indAr = calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        indAr[i] = 0;
    }
    structure[0] = 0;
    int curInd = -99;
    while (1) {
        curInd = -99;
        for (int i = 0; i < size; i++) {
            if (indAr[i] != 1) {
                curInd = i;
                break;
            }

        }
        if (curInd == -99)
            break;
        int lenght = 0;
        int position = curInd;
        while (indAr[position] != 1) {
            indAr[position] = 1;
            position = sbox[position];
            lenght++;
        }

        structure[structure[0] * 2 + 1] = curInd;
        structure[structure[0] * 2 + 2] = lenght;
        structure[0]++;
    }
    int max = 0;
    max = structure[structure[0] - 1 * 2 + 2];
    for (int i = structure[0] - 1; i >= 0; i--) {
        //printf("%d:%d, ", structure[i * 2 + 1], structure[i * 2 + 2]);
        if (structure[i * 2 + 2] > max) {
            max = structure[i * 2 + 2];
        }
    }
    free(structure);
    free(indAr);
    return max;
}

int fixedPoints(const int *sbox, int size) {
    int counter = 0;
    for (int i = 0; i < 256; i++)
        if (sbox[i] == i || sbox[i] == ~i) {
            counter++;
        }
    if (counter > 0)
        printf("\nCapacity of fixed points: %d", counter);
    else
        printf("\nFixed points ain't found\n");

    return counter;
}

int minDegCalculation(const int *arr, int size, int count) {
    int *minDEC = calloc(size - 1, sizeof(int));
    int result = 0;
    int *temp = calloc(size, sizeof(int));
    for (int i = 0; i < size - 1; ++i) {
        //printf("\nCombination %d", i + 1);
        for (int j = 0; j < size; ++j) {
            temp[j] = arr[i * size + j];
        }
        int dec = algebraicDeg(temp, size, count);
        //printf("\nALGEBRAIC DEGREE = %d ", dec);
        //printf("\n");
        minDEC[i] = dec;
    }
    int minD = 0;
    minD = minDEC[0];
    //printf("\nDEC ARRAY");
    //printf("\n");
    for (int y = 0; y < size - 1; ++y) {
        //printf("%d ", minDEC[y]);
        if (minDEC[y] < minD) {
            minD = minDEC[y];
        }
    }
    result = minD;
    free(minDEC);
    free(temp);
    return result;
}

int minDegree(int *sbox, int size, int count) {
    int *ar = SBoxToBooleanFunc(sbox, size, count);
    int *ar2 = linearCombinations(ar, size, count);
    int result = minDegCalculation(ar2, size, count);
    free(ar);
    free(ar2);
    return result;
}

void buildOneRow(int *arr, int *monomials) {
    monomials[0] = 1;
    //monomials x1,x8,y1,...,y8
    for (int i = 1; i <= 16; i++)
        monomials[i] = arr[i - 1];
    int pos = 17;
    //monomials x1x2
    for (int i = 1; i < 16; i++) {
        for (int j = i + 1; j <= 16; j++) {
            monomials[pos] = monomials[i] & monomials[j];
            pos++;
        }
    }
    //monomials x1x2x3
    for (int i = 1; i < 15; i++) {
        for (int j = i + 1; j <= 16; j++) {
            for (int k = j + 1; k <= 16; k++) {
                monomials[pos] = monomials[i] & monomials[j] & monomials[k];
                pos++;
            }
        }
    }
}

int rankCalculation(int rows, int cols, int a[rows][cols]) {
    int m = cols;
    int n = rows;

    int rank = cols;
    int *line = calloc(cols, sizeof(int));
    for (int i = 0; i < 697; i++)
        line[i] = 0;
    for (int i = 0; i < m; ++i) {
        int j;
        for (j = 0; j < n; ++j)
            if (!line[j] && a[j][i])
                break;
        if (j == n)
            --rank;
        else {
            line[j] = 1;
            for (int k = 0; k < n; ++k)
                if (k != j && a[k][i])
                    for (int p = i + 1; p < m; ++p)
                        a[k][p] ^= a[j][p] & a[k][i];
        }
    }
    free(line);
    return rank;
}

int algebraicImmunity(int *sbox, int size, int count) {
    int rows = raiseToPower(2, count);
    int calc = 0;
    int cols = 0;
    int result = 0;
    for (int d = 0; d < count; ++d) {
        calc = numOfCombinations(count + count, d);
        cols = cols + calc;
        if (cols > rows) {
            result = d;
            break;
        }
    }
    //printf("\nnum of comb %d \n", cols);
    int mat[rows][cols];
    int tmp[cols];
    int values[count + count];
    int *bin = calloc(count, sizeof(int));
    int *input_values = calloc(size * count, sizeof(int));
    for (int i = 0; i < size; ++i) {
        bin = valueToBinary(i, count);
        for (int j = 0; j < count; ++j) {
            input_values[i * count + j] = bin[j];
            //printf("%d ", input_values[i*count+j]);
        }
        //printf("\n");
    }
    for (int i = 0; i < 256; i++) {
        int y = sbox[i];
        values[0] = input_values[i * count + 0];
        values[1] = input_values[i * count + 1];
        values[2] = input_values[i * count + 2];
        values[3] = input_values[i * count + 3];
        values[4] = input_values[i * count + 4];
        values[5] = input_values[i * count + 5];
        values[6] = input_values[i * count + 6];
        values[7] = input_values[i * count + 7];
        values[8] = input_values[y * count + 0];
        values[9] = input_values[y * count + 1];
        values[10] = input_values[y * count + 2];
        values[11] = input_values[y * count + 3];
        values[12] = input_values[y * count + 4];
        values[13] = input_values[y * count + 5];
        values[14] = input_values[y * count + 6];
        values[15] = input_values[y * count + 7];
        buildOneRow((int *) &values, (int *) &mat[i]);
    }
    int rank = rankCalculation(rows,cols,mat);
    free(bin);
    free(input_values);
    //printf("%d", rank);
    if (rank == rows){
        return result;
    } else {
        return result-1;
    }
}

int numOfCombinations(int n, int d) {
    if (n == d)
        return 1;
    if (d == 1)
        return n;
    if (d == 0)
        return 1;
    return numOfCombinations(n - 1, d - 1) + numOfCombinations(n - 1, d);
}