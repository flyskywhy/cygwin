#!/bin/sh

xmlcatalog --noout --del "-//OASIS//DTD DocBook XML V4.1.2//EN" /etc/xml/catalog
xmlcatalog --noout --del http://www.oasis-open.org/docbook/xml/4.1.2/ /etc/xml/catalog
