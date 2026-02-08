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

## 1) Vivado Start

Start 'gnome-terminal'

Run following commands
```
   copy script contents here
```

![vivado_start_window](./Images/vivado_pg_00.jpg "Vivado start dialog")

## 2) Setup - Open Hardware Manager

![hw_manager](./Images/vivado_pg_01.jpg "HW Manager")

If starting an ILA session for the first time, continue to Section **3**.

If hardware selection has been done previously, skip Section 3 and
proceed to Section **4**.

## 3) Select Target Hardware

## 4) Load Probe (ILA File - <probe>.ltx)

## 5) Trigger

## 6) Shutdown

# References

NOTE - Running Vivado may not render correctly on full 32-bit graphics
       environment.
````
       Some "colors" are rendered as "see through".

       I forget how, but there may be a start option on the
       "Windows to Linux" 'mstsc' tool to select a 24-bit color
       pallette.  Vivado will render correctly then.
```

