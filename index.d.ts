declare class IPv4 {
  constructor(ipAddress?: string|number);
  toString(): string;
}

declare class CIDR {
  constructor(cidr?: string);
  toString(): string;
}

export {
  IPv4,
  CIDR,
};
