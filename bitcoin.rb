#!/usr/bin/env ruby
require 'rubygems'
require 'serialport'
require 'json'
require 'net/http'
require 'bigdecimal'
require 'optparse'

@options = {}

opt_parser = OptionParser.new do |opt|
  opt.banner = "Usage: bitcoin.rb SERIALPORT [OPTIONS]"
  opt.separator  ""
  opt.separator  "Example:"
  opt.separator  "     ./bitcoin.rb /dev/ttyACM0"
  opt.separator  ""
  opt.separator  "Options"

  opt.on("-c","--console","Console output?") do
    @options[:console] = true
  end

  opt.on("-h","--help","help") do
    puts opt_parser
  end
end

opt_parser.parse!

case ARGV[0]
when nil
  puts "Specifiy port"
  puts opt_parser
  exit 1
end

@port = SerialPort.new(ARGV[0], 9600)

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

@usd_old = 0.0;
@eur_old = 0.0;

@port.puts "C=\n"
@port.puts "w=0505:Fetching Data ...\n"
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
  @eur_old = eur
  @usd_old = usd
  if @options[:console] == true
    puts "#{usd} Dollar"
    puts "#{eur} Euro"
  end
  sleep 15;
}
