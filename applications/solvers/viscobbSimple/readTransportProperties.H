//    singlePhaseTransportModel laminarTransport(U, phi);

//################ Add #############################
 IOdictionary transportProperties
    (
        IOobject
        (
            "transportProperties",
            runTime.constant(),
            mesh,
            IOobject::MUST_READ_IF_MODIFIED,
            IOobject::NO_WRITE
        )
    );


    // Reference Kinematic viscosity coefficient [m²/s]
    dimensionedScalar nu0(transportProperties.lookup("nu0"));

    // Kinematic viscosity Law coefficients
    dimensionedScalar a(transportProperties.lookup("a"));
    dimensionedScalar b(transportProperties.lookup("b"));
    dimensionedScalar A3(transportProperties.lookup("A3"));
    dimensionedScalar mu(transportProperties.lookup("mu"));

    // Rayleigh number [s⁴/(m⁴·K)] instead of // Thermal expansion coefficient [1/K]
    dimensionedScalar Ra(transportProperties.lookup("Ra"));

    // Thermal diffusivity coefficient [m²/s]
    dimensionedScalar DT(transportProperties.lookup("DT"));
//################ End #############################

/*
    // Thermal expansion coefficient [1/K]
    dimensionedScalar beta(laminarTransport.lookup("beta"));
*/
    // Reference temperature [K]
    dimensionedScalar TRef(transportProperties.lookup("TRef"));
/*
    // Laminar Prandtl number
    dimensionedScalar Pr(laminarTransport.lookup("Pr"));

    // Turbulent Prandtl number
    dimensionedScalar Prt(laminarTransport.lookup("Prt"));
*/

