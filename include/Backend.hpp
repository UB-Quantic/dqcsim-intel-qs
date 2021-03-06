#include <dqcsim>
#include <qureg.hpp>

using namespace dqcsim::wrap;

class IqsBackend {
    qhipster::mpi::Environment env;
    QubitRegister<ComplexSP> reg;
    int rank;

  public:
    IqsBackend(int argc, char *argv[]);
    void initialize(PluginState &state, ArbCmdQueue &&queue);
    void drop(PluginState &state);
    void allocate(PluginState &state, QubitSet &&qubits, ArbCmdQueue &&queue);
    void free(PluginState &state, QubitSet &&qubits);
    MeasurementSet gate(PluginState &state, Gate &&arg);
    void advance(PluginState &state, Cycle cycle);
    ArbData arb_cmd(PluginState &state, ArbCmd cmd);

  private:
    void apply_gate(QubitIndex, Matrix);
    void apply_controlled_gate(QubitIndex, QubitIndex, Matrix);
};