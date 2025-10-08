#include <print>
#include <valarray>
#include <string>
#include <map> // for the parameters

typedef std::valarray<double> state_t; // create a short name to represent the system state type
typedef std::map<std::string, double> params_t;

void initial_conditions(state_t & s, double t0);
void print(const state_t & s, double t);
void fderiv(const state_t & s, state_t & dsdt, double t, params_t & p);
template <class deriv_t, class s_t, class print_t>
void integrate_rk4(deriv_t deriv, s_t & s, double tinit, double tend, double dt, params_t & params, print_t writer);

int main(void)
{
    int N = 3;
    state_t S(N);
    params_t params;

    params["sigma"] = 10.0;
    params["rho"]   = 28.0;
    params["beta"]  = 8.0 / 3.0;
    initial_conditions(S, 0.0);

    double dt = 0.01;
    double tf = 40.0;
    integrate_rk4(fderiv, S, 0.0, tf, dt, params, print);

    return 0;
}

void fderiv(const state_t & s, state_t & dsdt, double t, params_t & params)
{
  double sigma = params["sigma"];
  double rho   = params["rho"];
  double beta  = params["beta"];

  dsdt[0] = sigma * (s[1] - s[0]);
  dsdt[1] = s[0] * (rho - s[2]) - s[1];
  dsdt[2] = s[0] * s[1] - beta * s[2];
}

void initial_conditions(state_t & s, double t0)
{
  s[0] = 10.0;
  s[1] = 1.0;
  s[2] = 1.0;
}

void print(const state_t & s, double t)
{
  std::println("{:25.16e},{:25.16e},{:25.16e},{:25.16e}", t, s[0], s[1], s[2]);
}

template <class deriv_t, class s_t, class print_t>
void integrate_rk4(deriv_t deriv, s_t & s, double tinit, double tend, double dt, params_t & params, print_t writer)
{
  // vector to store derivs
    s_t k1(s.size()), k2(s.size()), k3(s.size()), k4(s.size());

  // time loop
  for (double t = tinit; t <= tend; t = t + dt) {
    deriv(s, k1, t, params);
    s_t s2 = s + (dt * 0.5) * k1;
    deriv(s2, k2, t + 0.5 * dt, params);
    s_t s3 = s + (dt * 0.5) * k2;
    deriv(s3, k3, t + 0.5 * dt, params);
    s_t s4 = s + dt * k3;
    deriv(s4, k4, t + dt, params);

    s = s + (dt / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);

    // write new state
    writer(s, t + dt);
  }
}