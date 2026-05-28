# How to Create an FPGA Project using Vivado

**ROUGH DRAFT**

Steps generally taken from the youTube _tutorial_:
```
   <link-here>
```
Problem was the tutorial was using an earlier version than the one I was
using, which was _version 2024.2_.

The notes here are an attempt to show how to define an FPGA project that
generates:

   1. An FPGA circuit defined by a **.bit** file.

   2. A _Xilinx Support Archive_ (**.xsa**) that configures how
      a **.bit** file is to be installed into a selected FPGA.

   3. A **.elf** file that can be downloaded and started on
      a _microprocessor_ component of the overall FPGA.

These _products_ from the **Vivado** tool are to be downloaded into a
selected FPGA.

Note - These items and terminology are specific the **Xilinx** toolset.

## New Project

These steps:
```
   (a) Select "New Project" link.  Starts wizard/dialog

       (i) Select RTL project

       (ii) Board selection - select the BOARDS tab ... it's easier
            to look up boards by their names.  For example

                  VCU128 - For UltraScale FPGA
                  VHK158 - For Versal (or is is Zynq?) FPGA

       (iii) Select: "Create Block Diagram"

       (iv) "Add IP" - This is where things can get complicated.
```

Select `Mouse-Button-2` for pop-up-menu that lists all the FPGA sub-modules
and components that can be activated on the board selected in step (ii).

It's massive.

Small components ... medium components ... to massive components such as
full up microprocessors (e.g. Xilinx's definition of the old DLX RISC
processor, they call the "MicroBlaze".

Alternatively, one can define a new component.  And then package it into what
_Xilinx_ (and I guess general FPGA parlance) call **Intellectual Property**
(IP).  It's such an odd terminology, that some instantiation of a digital
 circuit is called **Intellectual Property**.

Anyway, these notes are about how to define a _project_ by connecting
already existing **IP** components.

**Note**: At step (i) one can select one of a set of _pre-defined_ projects,
such as a fully-defined **MicroBlaze** system.  The _path_ of the _wizard_
is different, but a _pre-defined_ project might meet the requirements of
a system, perhaps with some changes or other **IP** items added.

Continue:
```
   (b) Complete circuit:

       (i) Select: "Run Block Automation"

       (ii) Select: "Run Connectin Automation"

          This will complete the connections between components.

          As the tutor says "Vivado is board aware".

   (c) Select: "Validate Design"

       Possibly select "Regenerate Layout"

   (d) Save (Block Design)

   (e) Select 'Mouse Button 2'.

       From pop-up menu list, select:

       (i) Generate Output Products (or is it "Generate Block Design")

           I think this takes a long time

       (ii) Select "Create HDL Wrapper"

            Let Vivado manage wrapper and auto-update

            "Implement Design" means:
            -------------------------
               Generate Bit Stream
               1) Synthesis
               2) Implementation
               3) Generate bit stream

            ATTEN - ATTEN - ATTEN : This can take a really long time to run

            At the end there is a pop-up saying it worked or failed.

            If it worked, select:

               "Open Implementation Design"

            Check (or run) "Timing Summary Report"

               Verify not setup or hold-time violations
```
At this point I think the **.bit** and **.xsa** files have been generated. 

Next step is **Export Hardware**.

```
   (a) File-->Export HW

       Got lost here.  The old Vivado in the tutorial linked up to the
       tool called SDK.

```
Instead of creating a custom circuit I selected a _pre-defined_ project for
the **Microblaze** targeted to a **VCU128** (i.e. _UltraScale_ FPGA).  So
I had a **.xsa** and **.bit** file generated from that.

At this point I started **Vitis** ... their _overall_ IDE.

I stumbled through creation of an **application** that generated a **.elf**.

I was able to install the **.bit**, **.xsa**, and **.elf** to a **VCU128**
board and ran OK.

The problem was when I tried this targeted to a **VHK158** I ran into all
sorts of problems.

**ROUGH DRAFT**

