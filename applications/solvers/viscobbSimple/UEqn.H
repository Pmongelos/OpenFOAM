    // Solve the momentum equation

    tmp<fvVectorMatrix> UEqn
    (
      - fvm::laplacian(NUEff, U)
      - (dev(twoSymm(fvc::grad(U))) & fvc::grad(NUEff))
      - fvc::div(NUEff*dev(fvc::grad(U)().T()))
/*
        fvm::div(phi, U)
      + turbulence->divDevReff(U)
     ==
        fvOptions(U)
*/    );

    UEqn().relax();

//    fvOptions.constrain(UEqn());

    if (simple.momentumPredictor())
    {
        solve
        (
            UEqn()
          ==
            fvc::reconstruct
            (
                (
                  - ghf*fvc::snGrad(rhok)
                  - fvc::snGrad(p_rgh)
                )*mesh.magSf()
            )
        );

//        fvOptions.correct(U);
    }
