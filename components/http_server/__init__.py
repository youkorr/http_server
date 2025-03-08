import esphome.codegen as cg

http_server_ns = cg.esphome_ns.namespace('http_server')
HttpServer = http_server_ns.class_('HttpServer', cg.Component)

def to_code(config):
    var = cg.new_Pvariable(config[cg.CONF_ID])
    yield cg.register_component(var, config)
