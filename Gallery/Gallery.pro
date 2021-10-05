TEMPLATE = subdirs

SUBDIRS += \
    Core \
    Desktop

Desktop.depends = Core
