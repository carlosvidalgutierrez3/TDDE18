#include <string>
#include <vector>
//

struct Connection
{
double charge{};
};


class Component
{
public:
  Component(std::string name, Connection &a, Connection &b);
  virtual ~Component() = default;
  virtual double current()=0;
  virtual void simulate(double dt)=0;
  double get_voltage();
  std::string name{};

protected:
  Connection &a;
  Connection &b;
//std::string name{};
};


class Battery: public Component
{
public:
  Battery(std::string name, double voltage, Connection &a, Connection &b);
  double current() override;
  void simulate(double dt) override;

private:
  double voltage{};
};


class Resistor: public Component
{
public:
  Resistor(std::string name, double resistance, Connection &a, Connection &b);
  double current() override;
  void simulate(double dt) override;

private:
  double resistance{};
};


class Capacitor: public Component
{
public:
  Capacitor(std::string name, double farad, double load, Connection &a, Connection &b);
    double current() override;
    void simulate(double dt) override;

private:
  double farad{};
  double load{};
};


void simulate(std::vector<Component*> circuit, int iterations, int n_outputs, double dt);
