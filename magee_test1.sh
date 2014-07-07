#!/bin/bash
# the tail of the result should look like this:
# 
#   two
#   three
#   four
#

./magee -cpu -f one two -est three four | more

