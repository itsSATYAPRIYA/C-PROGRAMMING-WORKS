#include <stdio.h>
#include <math.h>

void notes_on_quadratic_equations() {
    printf("\tTake a short note on quadratic equations.\n");
    printf("\t-------------------------------------------------------------------------------------------\n");
    printf("\tA quadratic equation is a second-degree polynomial equation of the form ax^2 + bx + c\n");
    printf("\tWhere a,b,c are constants\n \tx is the variable\n \ta not equals to 0\n");
    printf("\tdiscriminant = (b*b) - 4*a*c\n \twhere a,b,c are coeficients.\n");
    printf("\t\n");
    printf("\tNATURE OF ROOTS BASED ON DISCRIMINANTS.\n");
    printf("\tIf Discriminant is > 0\n");
    printf("\t\t*Two real roots\n");
    printf("\t\t*The quadratic equation intersects the x-axis at two distinct points.\n");
    printf("\tIf Discriminant = 0\n");
    printf("\t\t*Exactly one real root (double root).");
    printf("\t\t*The quadratic equation touches the x-axis at one point.\n");
    printf("\tIf Discriminant < 0\n");
    printf("\t\t*No real roots, but two complex roots.\n");
    printf("\t\t*The quadratic equation does not intersect the x-axis.\n");
    printf("\t-------------------------------------------------------------------------------------------\n");
}

void calculate_equations(float a, float b, float c) {
    float discriminant, root1, root2, real, imaginary;

    discriminant = (b * b) - 4 * a * c;

    printf("Discriminant: %f\n", discriminant);

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two distinct real roots: root1 = %f, root2 = %f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("One real root: root = %f\n", root1);
    } else {
        real = -b / (2 * a);
        imaginary = sqrt(-discriminant) / (2 * a);
        printf("Two complex roots: root1 = %f + %fi, root2 = %f - %fi\n", real, imaginary, real, imaginary);
    }
}

int main() {
    int choice;

    printf("Choose an option:\n");
    printf("1. Display a short note on quadratic equations\n");
    printf("2. Calculate the roots of a quadratic equation\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            notes_on_quadratic_equations();
            break;
        case 2:
            float a, b, c;
            printf("Enter the coefficients of the quadratic equation (a, b, c): ");
            scanf("%f %f %f", &a, &b, &c);
            calculate_equations(a, b, c);
            break;
        case 3:
            // code to exit the program
            break;
        default:
            printf("Invalid choice. Please choose a valid option.\n");
            break;
    }

    return 0;
}