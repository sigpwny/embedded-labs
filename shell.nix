{ pkgs ? import <nixpkgs> {} }:
let
  # OpenOCD 0.12.0 does not have the MSPM0 flash driver yet.
  openocd = pkgs.openocd.overrideAttrs (old: {
    version = "0.12.0-dev-2026-10-18";
    src = pkgs.fetchzip {
      url = "https://github.com/openocd-org/openocd/archive/2893f940012e19cda8ccb6038766b0d77f26bd0e.tar.gz";
      sha256 = "00xwmghmwg4plgqqhci8bkg8x4a1r76g9m4kwzpcl9zqg23ydgai";
    };
    nativeBuildInputs = old.nativeBuildInputs ++ [ pkgs.autoreconfHook pkgs.texinfo ];
    configureFlags = old.configureFlags ++ [ "--disable-internal-jimtcl" "--disable-internal-libjaylink" ];
  });
in pkgs.mkShell {
  packages = [ pkgs.gcc-arm-embedded pkgs.gnumake pkgs.gitMinimal openocd ];
}
