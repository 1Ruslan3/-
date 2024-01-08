#include <stdio.h>
#include <stdarg.h>

typedef struct {
    double x;
    double y;
} Point;

int is_convex_polygon(int num_vertices, ...);
double evaluate_polynomial(double x, int degree, ...);

int main() {
    int result1 = is_convex_polygon(4, (double)0, (double)0, (double)2, (double)2, (double)4, (double)0, (double)2, (double)-2); // Пример выпуклого четырехугольника
    printf("Is the polygon convex? %s\n", result1 ? "No" : "Yes"); 

    int result2 = is_convex_polygon(4, (double)0, (double)0, (double)1, (double)0, (double)0.5, (double)1, (double)-0.5, (double)1); // Пример невыпуклого четырехугольника
    printf("Is the polygon convex? %s\n", result2 ? "No" : "Yes");

    double result3 = evaluate_polynomial(2.0, 3, 2.0, -3.0, 1.0); // 2.0 * x^2 - 3.0 * x + 1.0
    printf("Result: %.2f\n", result3);

    double result4 = evaluate_polynomial(1.5, 4, 1.0, 2.0, -1.0, 3.0, 4.0); // 1.0 * x^4 + 2.0 * x^3 - 1.0 * x^2 + 3.0 * x + 4.0
    printf("Result: %.2f\n", result4);
    return 0;
}

int orientation(Point p1, Point p2, Point p3) {
    double value = (p2.y - p1.y) * (p3.x - p2.x) - (p3.y - p2.y) * (p2.x - p1.x);
    if (value == 0) {
        return 0; // Коллинеарные точки
    }
    else if (value > 0) {
        return 1; // По часовой стрелке
    }
    else {
        return -1; // Против часовой стрелки
    }
}

int is_convex_polygon(int num_vertices, ...) {
    va_list vertices;
    va_start(vertices, num_vertices);

    Point p1, p2, p3;
    int orientation_value = 0;
    int current_orientation = 0;

    p1.x = va_arg(vertices, double);
    p1.y = va_arg(vertices, double);
    p2.x = va_arg(vertices, double);
    p2.y = va_arg(vertices, double);
    p3.x = va_arg(vertices, double);
    p3.y = va_arg(vertices, double);
    orientation_value = orientation(p2, p3, p1);

    for (int i = 2; i < num_vertices + 1; i++) {
        p1 = p2;
        p2 = p3;
        p3.x = va_arg(vertices, double);
        p3.y = va_arg(vertices, double);
        current_orientation = orientation(p1, p2, p3);

        if (current_orientation != 0 && current_orientation != orientation_value) {
            va_end(vertices);
            return 0; // Многоугольник не выпуклый
        }
    }

    va_end(vertices);
    return 1; // Многоугольник выпуклый
}

double evaluate_polynomial(double x, int degree, ...) {
    va_list coefficients;
    va_start(coefficients, degree);

    double result = 0.0;
    double power_of_x = 1.0;

    for (int i = 0; i <= degree; i++) {
        double coefficient = va_arg(coefficients, double);
        result += coefficient * power_of_x;
        power_of_x *= x;
    }

    va_end(coefficients);

    return result;
}