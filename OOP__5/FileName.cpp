#include <iostream>
#include <vector>
#include <memory>

const double PI = 3.14159265358979323846;

// ����������� ���� ����������� ���
class GeometricShape {
public:
    // ³��������� ����� ��� ���������� ����� �������
    virtual double calculateSurfaceArea() const = 0;

    // ³��������� ����� ��� ���������� ��'���
    virtual double calculateVolume() const = 0;

    // ³��������� ����������
    virtual ~GeometricShape() = default;
};

// �������� ���� ϳ�����
class Pyramid : public GeometricShape {
private:
    double baseArea; // ����� ������ ������
    double height;   // ������ ������

public:
    // �����������
    Pyramid(double baseArea, double height) : baseArea(baseArea), height(height) {}

    // ��������� ����������� ������ ��� ���������� ����� ������� ������
    double calculateSurfaceArea() const override {
        // ������� ��� ���������� ����� ������� ������
        return baseArea + 0.5 * baseArea * sqrt(4 * pow(height, 2) + pow(baseArea, 2));
    }

    // ��������� ����������� ������ ��� ���������� ��'��� ������
    double calculateVolume() const override {
        // ������� ��� ���������� ��'��� ������
        return (1.0 / 3.0) * baseArea * height;
    }
};

// �������� ���� ����
class Sphere : public GeometricShape {
private:
    double radius; // ����� ���

public:
    // �����������
    Sphere(double radius) : radius(radius) {}

    // ��������� ����������� ������ ��� ���������� ����� ������� ���
    double calculateSurfaceArea() const override {
        // ������� ��� ���������� ����� ������� ���
        return 4.0 * PI * pow(radius, 2);
    }

    // ��������� ����������� ������ ��� ���������� ��'��� ���
    double calculateVolume() const override {
        // ������� ��� ���������� ��'��� ���
        return (4.0 / 3.0) * PI * pow(radius, 3);
    }
};

int main() {
    setlocale(LC_ALL, "Ukr");

    // ������������ ����������� ����� ��������� �� ������� ����
    std::vector<std::unique_ptr<GeometricShape>> shapes;
    shapes.push_back(std::make_unique<Pyramid>(10.0, 5.0));
    shapes.push_back(std::make_unique<Sphere>(7.0));

    // ������� � ��'������ ����� ����������� ����
    for (const auto& shape : shapes) {
        std::cout << "Surface area: " << shape->calculateSurfaceArea() << std::endl;
        std::cout << "Volume: " << shape->calculateVolume() << std::endl;
        std::cout << "-------------------------\n";
    }

    return 0;
}
