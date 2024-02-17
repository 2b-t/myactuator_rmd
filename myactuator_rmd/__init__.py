"""
Author: Tobit Flatscher (github.com/2b-t)

Imports all submodules
Taken from https://stackoverflow.com/a/3365846
"""

import pkgutil


__all__ = []
for loader, module_name, is_pkg in pkgutil.walk_packages(__path__):
    __all__.append(module_name)
    _module = loader.find_module(module_name).load_module(module_name)
    globals()[module_name] = _module
