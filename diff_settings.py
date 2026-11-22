import argparse
import os

# Which version diff.py compares against: KH_VERSION=jp (default), fm or eu - the one configure.py was last run for.
BASENAMES = {"jp": "SLPS_251.05", "fm": "SLPS_251.98", "eu": "SCES_509.67"}


def apply(config, args):
    version = os.environ.get("KH_VERSION", "jp")
    basename = BASENAMES[version]
    config["arch"] = "mipsee"
    config["baseimg"] = f"{basename}.rom"
    config["myimg"] = f"build/{version}/{basename}.rom"
    config["mapfile"] = f"build/{version}/{basename}.map"
    config["source_directories"] = [
        "src",
        "asm",
        "include",
        "assets",
    ]
    config["make_command"] = ["ninja"]
    config["objdump_flags"] = ["-Mreg-names=n32"]
    config["expected_dir"] = f"expected/"
