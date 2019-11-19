#include "MooseINSApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<MooseINSApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MooseINSApp::MooseINSApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseINSApp::registerAll(_factory, _action_factory, _syntax);
}

MooseINSApp::~MooseINSApp() {}

void
MooseINSApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MooseINSApp"});
  Registry::registerActionsTo(af, {"MooseINSApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MooseINSApp::registerApps()
{
  registerApp(MooseINSApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MooseINSApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseINSApp::registerAll(f, af, s);
}
extern "C" void
MooseINSApp__registerApps()
{
  MooseINSApp::registerApps();
}
