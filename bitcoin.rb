#!/usr/bin/env ruby
require 'rubygems'
require 'serialport'
require 'json'
require 'net/http'
@port = SerialPort.new( '/dev/ttyACM0', 9600)

@usd_old = 0;
@eur_old = 0;

def check_usd(usd)
  if usd < @usd_old
    return '%'
  else
    return '&'
  end
end
def check_eur(eur)
  if eur < @eur_old
    return '%'
  else
    return '&'
  end
end

loop {
  responseusd =  Net::HTTP.get('data.mtgox.com', '/api/1/BTCUSD/ticker')
  parsedusd = JSON.parse(responseusd)
  usd = parsedusd["return"]["last_local"]["value"].split('.').first

  responseeur =  Net::HTTP.get('data.mtgox.com', '/api/1/BTCEUR/ticker')
  parsedeur = JSON.parse(responseeur)
  eur = parsedeur["return"]["last_local"]["value"].split('.').first
  @port.puts "C%$#{check_usd(usd.to_i)}#{usd}!#{check_eur(eur.to_i)}#{eur}"
  @eur_old = eur.to_i
  @usd_old = usd.to_i
  sleep 30;
}


