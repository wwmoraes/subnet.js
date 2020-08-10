# subnet.js

> native-performance IP engineering for NodeJS/TypeScript

## Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Usage](#usage)
- [Contributing](../CONTRIBUTING.md)

## About <a name = "about"></a>

Node addon API wrapper around [subnet CLI](https://github.com/wwmoraes/subnet)
classes to parse IPv4 and CIDR.

## Getting Started <a name = "getting_started"></a>

IP engineering operations on NodeJS requires `BigInt` usage, which is cumbersome
and slow due to the amount of implicit conversions. The standard number is even
worse, and involves double conversions back and forth.

the [subnet](https://github.com/wwmoraes/subnet) classes for IP and CIDR do store
all data in proper data types, and also prevents conversions between operations,
allowing an application to handle hundreds of CIDR operations fast.

The main reason for such tools is a subnet web application I'll work on in my
current company, with fancy D3.js presentation that'll serve as both planner visual documentation for all engineers. IP engineering should not be difficult! 😄

### Prerequisites

- python 3+ (the build was tested with 3.8)
- clang/g++
- node-gyp (usually already present on newer Node installations)

### Installing

clone the subnet into `subnet/` folder at the repository root

```shell
git clone git@github.com:wwmoraes/subnet.git subnet
```

and then run `yarn` to build it.

TODO: add git submodule and publish package

> Use your package manager of choice, as yarn
>
> ```shell
> yarn add subnet.js
> ```
>
> or npm
>
> ```shell
> npm install subnet.js
> ```

## Usage <a name = "usage"></a>

```typescript
import subnet from 'subnet.js';

let myIP = new subnet.IPv4("10.0.0.1");
console.log(myIP.toString());

let myCIDR = new subnet.CIDR("10.0.0.1/16");
console.log(myCIDR.toString());
```
