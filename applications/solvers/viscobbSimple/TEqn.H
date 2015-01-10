{
/*    alphat = turbulence->nut()/Prt;
    alphat.correctBoundaryConditions();

    volScalarField alphaEff("alphaEff", turbulence->nu()/Pr + alphat);
*/
    fvScalarMatrix TEqn
    (
        fvm::div(phi, T)
      - fvm::laplacian(DT, T)//change alphaEff for DT
     ==
        fvOptions(T)
    );

    TEqn.relax();

    fvOptions.constrain(TEqn);

    TEqn.solve();

    fvOptions.correct(T);

//Add for kinematic viscosity coefficient calculation #############

    NUEff = A1*atan(A3*(T - TRef - b)) + A2;

    rhok = 1.0 - beta*(T - TRef);
}
