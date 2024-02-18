"""
@file __init__.py
@mainpage
   Imports all submodules; taken from https://stackoverflow.com/a/3365846
@author
   Tobit Flatscher (github.com/2b-t)
"""

import pkgutil


__all__ = []
for loader, module_name, is_pkg in pkgutil.walk_packages(__path__):
    __all__.append(module_name)
    _module = loader.find_module(module_name).load_module(module_name)
    globals()[module_name] = _module
