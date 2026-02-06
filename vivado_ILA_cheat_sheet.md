# Using (Xilinx) Vivado Integrated Logic Analyser (ILA)

The following are raw notes, from a software developer's perspective, on
using the Vivado tool to debug software that interacts with an
FPGA design.

An **Integrated Logic Analyzer** (ILA) is additional FPGA circuitry added
to a design.  The ILA allows examination (i.e. **probe**) of the behavior
of an FPGA circuit, usually in response to software commands written to
registers.  The ILA is (likely) not included in the final FPGA product.
It is only appended to the base FPGA circuitry and allows the developer to
observe/probe circuit behavior, mostly to debug software, but one might
even uncover circuitry bugs.

The FPGA engineer(s) design the base circuitry.  They call this the **IP**,
which means _Intellectual-Property_.  They also often refer to it as the
**Register Transfer Language** (RTL).  It's all evolutionary terminology
from the olden days when the first circuit designs were implemented using
**Verilog Hardware Definition Lanaguage** (VHDL), etc.  A lot has happened
in 50 years.

## Vivado Start

## Setup - Open Hardware Manager

## Select Target Hardware

## Add Probes

## Trigger

## Shutdown

# References

