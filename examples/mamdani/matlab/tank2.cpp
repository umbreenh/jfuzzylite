#include <fl/Headers.h>

int main(int argc, char** argv){
fl::Engine* engine = new fl::Engine;
engine->setName("tank");

fl::InputVariable* inputVariable1 = new fl::InputVariable;
inputVariable1->setEnabled(true);
inputVariable1->setName("level");
inputVariable1->setRange(-1.00000000, 1.00000000);
inputVariable1->addTerm(new fl::Trapezoid("high", -2.00000000, -1.00000000, -0.80000000, -0.00100000));
inputVariable1->addTerm(new fl::Triangle("good", -0.15000000, 0.00000000, 0.50000000));
inputVariable1->addTerm(new fl::Trapezoid("low", 0.00100000, 0.80000000, 1.00000000, 1.50000000));
engine->addInputVariable(inputVariable1);

fl::InputVariable* inputVariable2 = new fl::InputVariable;
inputVariable2->setEnabled(true);
inputVariable2->setName("change");
inputVariable2->setRange(-0.10000000, 0.10000000);
inputVariable2->addTerm(new fl::Trapezoid("falling", -0.14000000, -0.10000000, -0.06000000, 0.00000000));
inputVariable2->addTerm(new fl::Trapezoid("rising", -0.00100000, 0.06000000, 0.10000000, 0.14000000));
engine->addInputVariable(inputVariable2);

fl::OutputVariable* outputVariable = new fl::OutputVariable;
outputVariable->setEnabled(true);
outputVariable->setName("valve");
outputVariable->setRange(-1.00000000, 1.00000000);
outputVariable->setLockOutputRange(false);
outputVariable->setDefaultValue(fl::nan);
outputVariable->setLockValidOutput(false);
outputVariable->setDefuzzifier(new fl::Centroid(200));
outputVariable->fuzzyOutput()->setAccumulation(new fl::Maximum);
outputVariable->addTerm(new fl::Triangle("close_fast", -1.00000000, -0.90000000, -0.80000000));
outputVariable->addTerm(new fl::Triangle("close_slow", -0.60000000, -0.50000000, -0.40000000));
outputVariable->addTerm(new fl::Triangle("no_change", -0.10000000, 0.00000000, 0.10000000));
outputVariable->addTerm(new fl::Triangle("open_slow", 0.40000000, 0.50000000, 0.60000000));
outputVariable->addTerm(new fl::Triangle("open_fast", 0.80000000, 0.90000000, 1.00000000));
engine->addOutputVariable(outputVariable);

fl::RuleBlock* ruleBlock = new fl::RuleBlock;
ruleBlock->setEnabled(true);
ruleBlock->setName("");
ruleBlock->setConjunction(new fl::AlgebraicProduct);
ruleBlock->setDisjunction(new fl::AlgebraicSum);
ruleBlock->setActivation(new fl::AlgebraicProduct);
ruleBlock->addRule(fl::Rule::parse("if level is low then valve is open_fast", engine));
ruleBlock->addRule(fl::Rule::parse("if level is high then valve is close_fast", engine));
ruleBlock->addRule(fl::Rule::parse("if level is good and change is rising then valve is close_slow", engine));
ruleBlock->addRule(fl::Rule::parse("if level is good and change is falling then valve is open_slow", engine));
engine->addRuleBlock(ruleBlock);


}
