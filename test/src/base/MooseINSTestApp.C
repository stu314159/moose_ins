//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MooseINSTestApp.h"
#include "MooseINSApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<MooseINSTestApp>()
{
  InputParameters params = validParams<MooseINSApp>();
  return params;
}

MooseINSTestApp::MooseINSTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MooseINSTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MooseINSTestApp::~MooseINSTestApp() {}

void
MooseINSTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MooseINSApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MooseINSTestApp"});
    Registry::registerActionsTo(af, {"MooseINSTestApp"});
  }
}

void
MooseINSTestApp::registerApps()
{
  registerApp(MooseINSApp);
  registerApp(MooseINSTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MooseINSTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MooseINSTestApp::registerAll(f, af, s);
}
extern "C" void
MooseINSTestApp__registerApps()
{
  MooseINSTestApp::registerApps();
}
