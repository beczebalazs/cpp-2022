#include "util.h"

int main() {
    printf("6. FELADAT:\n");
    testIsSquare("points.txt");

    printf("\n7.FELADAT:\n");
    int n;
    cout << "n=";
    cin >> n;
    printf("Randomly generated points:\n");
    Point *arr = createArray(n);
    printArray(arr, n);

    printf("\n9.FELADAT:\n");
    pair<Point, Point> res = closestPoints(arr, n);
    printf("Closest points:\n");
    res.first.print();
    res.second.print();

    printf("\n10.FELADAT:\n");
    res = farthestPoints(arr, n);
    printf("Farthest points:\n");
    res.first.print();
    res.second.print();

    printf("\n11.FELADAT:\n");
    printf("Unsorted array:\n");
    printArray(arr, n);
    printf("Sorted array:\n");
    sortPoints(arr, n);

    printf("\n12.FELADAT:\n");
    Point *result = farthestPointsFromOrigin(arr, n);
    printf("10 farthest points from origin:\n");
    printArray(result, min(n, 10));

    deletePoints(arr);
    deletePoints(result);

    printf("\nEXTRA FELADAT:\n");
    printf("A legkisebb tavolsag ket pont kozott: ");
    arr = createArray(100000);
    cout << closest(arr, n) << endl;
    return 0;
}
