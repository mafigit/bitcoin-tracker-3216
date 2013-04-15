#!/usr/bin/env ruby
require 'rubygems'
require 'serialport'
require 'json'
require 'net/http'
require 'bigdecimal'
@port = SerialPort.new( '/dev/ttyACM1', 9600)

@usd_old = 0.0;
@eur_old = 0.0;

def check_usd(usd)
  if usd < @usd_old
    return 'red'
  else
    return 'green'
  end
end
def check_eur(eur)
  if eur < @eur_old
    return 'red'
  else
    return 'green'
  end
end

@port.puts "C=\n"
loop {
  responseusd =  Net::HTTP.get('data.mtgox.com', '/api/1/BTCUSD/ticker')
  parsedusd = JSON.parse(responseusd)
  usd = parsedusd["return"]["last_local"]["value"].to_f

  responseeur =  Net::HTTP.get('data.mtgox.com', '/api/1/BTCEUR/ticker')
  parsedeur = JSON.parse(responseeur)
  eur = parsedeur["return"]["last_local"]["value"].to_f
  @port.puts "C=\n"
  @port.puts "f=normal\n"
  @port.puts "c=orange\n"
  @port.puts "w=0001:A\n"
  @port.puts "w=0008:B\n"

  @port.puts "c=#{check_usd(usd)}\n"
  @port.puts "f=small\n"
  @port.puts "w=0701:#{'%.2f' % usd}\n"

  @port.puts "c=#{check_eur(eur)}\n"
  @port.puts "f=small\n"
  @port.puts "w=0709:#{'%.2f' % eur}\n"
  @eur_old = eur.to_i
  @usd_old = usd.to_i
  sleep 15;
}


