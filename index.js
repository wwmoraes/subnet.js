const subnet = require('./build/Release/subnet.node');

module.exports = {
  IPv4: subnet.IPv4,
  CIDR: subnet.CIDR,
};
