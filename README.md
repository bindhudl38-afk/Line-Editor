# Simple Line Editor in C

## Project Description

This project is a simple command-line line editor developed in C. It allows users to create, view, insert, and delete lines of a small text document through terminal commands.

## Data Structure

The editor uses an **array of strings** to store document lines.

This data structure was selected because the editor handles a small text document and an array provides a simple way to access lines using line numbers.

## Features Implemented

* Insert a line
* Delete a line
* Display the document
* Display help
* Exit the editor

## Commands

* `I <line> <text>` - Insert a line
* `D <line>` - Delete a line
* `P` - Display the document
* `H` - Display help
* `E` - Exit

## Team Members

* Bindhu
* Chinmayi

## Compilation

Compile using GCC:

```bash
gcc editor.c -o editor
```

## Run

On Windows:

```bash
editor.exe
```

On Linux/macOS:

```bash
./editor
```

## Example

```text
> I 1 Hello World
Line inserted successfully.

> P

----- Document -----
1: Hello World
--------------------
```
